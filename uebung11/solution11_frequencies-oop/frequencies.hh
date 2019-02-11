#ifndef FREQUENCIES_HH
#define FREQUENCIES_HH

#include <iostream>
#include <cctype>
#include <vector>
#include <memory>

#include "plugin.hh"

template<typename Map, typename Filter>
class Frequencies
{

public:

  // Processes all letters obtained from source
  template<typename Source>
  void readData(Source& source)
  {
    while (true)
    {

      auto data = source.next();

      // abort if input closed
      if (not data.second)
        break;

      auto transformed = _filter.transform(data.first);
      if (not _filter.remove(transformed))
      {
        _map[transformed] += 1;
      }
    }
  }

  void printStatistics()
  {
    /*
    std::size_t total = 0;

    for (auto& entry : _map)
      total += entry.second;

    for (auto& entry : _map)
      std::cout << entry.first << ": " << static_cast<double>(entry.second)/total << std::endl;
    */

    for (auto plugin : _plugins)
    {
      std::cout << std::endl << "Output of plugin: " << plugin->name() << std::endl << std::endl;
      plugin->printStatistics(_map);
    }
  }

  Frequencies(Filter filter)
    : _filter(filter)
  {}

  void addPlugin(std::shared_ptr<AnalysisPlugin<Map>> plugin)
  {
    _plugins.push_back(plugin);
  }

private:

  Map _map;
  Filter _filter;
  std::vector<std::shared_ptr<AnalysisPlugin<Map>>> _plugins;

};

#endif // FREQUENCIES_HH
