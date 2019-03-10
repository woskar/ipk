#include <iostream>
#include <map>
#include <unordered_map>
#include <fstream>
#include <string>

#include "frequencies.hh"
#include "frequencysource.hh"
#include "filters.hh"

int main(int argc, char** argv)
{

  using Map = std::unordered_map<std::string,int>;

  StringFilter filter;

  Frequencies<Map,StringFilter> frequencies(filter);

  frequencies.addPlugin(std::make_shared<PrintFrequencies<Map>>());
  frequencies.addPlugin(std::make_shared<PrintTotalCount<Map>>());
  frequencies.addPlugin(std::make_shared<PrintMostFrequent<Map>>(20));

  for (int i = 1 ; i < argc ; ++i)
  {
    std::ifstream stream(argv[i]);
    auto source = streamWordSource(stream);
    frequencies.readData(source);
  }

  frequencies.printStatistics();
}
