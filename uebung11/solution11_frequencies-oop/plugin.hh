#ifndef PLUGIN_HH
#define PLUGIN_HH

#include <string>
#include <algorithm>
#include <iterator>

template<typename Map>
class AnalysisPlugin {

public:

  using Data = typename Map::key_type;
                                       // always add virtual destructor
  virtual ~AnalysisPlugin()
  {}

// returns the name of the plugin
  virtual std::string name() const = 0;

// does some statistics on the map and prints it to stdout
  virtual void printStatistics(const Map& map)
  {
// do nothing by default
  }

};


template<typename Map>
class PrintTotalCount
  : public AnalysisPlugin<Map>
{

public:

  std::string name() const override
  {
    return "TotalCount";
  }

  void printStatistics(const Map& map) override
  {
    std::size_t count = 0;
    for (auto& entry : map)
      count += entry.second;

    std::cout << "total count: " << count << std::endl;
  }

};


template<typename Map>
class PrintFrequencies
  : public AnalysisPlugin<Map>
{

public:

  std::string name() const override
  {
    return "Frequencies";
  }

  void printStatistics(const Map& map) override
  {
    std::size_t total = 0;

    for (auto& entry : map)
      total += entry.second;

    for (auto& entry : map)
      std::cout << entry.first << ": " << static_cast<double>(entry.second)/total << std::endl;

  }

};


template<typename Map>
class PrintMostFrequent
  : public AnalysisPlugin<Map>
{

public:

  std::string name() const override
  {
    return "Frequencies";
  }

  void printStatistics(const Map& map) override
  {

    std::vector<const typename Map::value_type*> list;

    for (auto& entry: map)
      list.push_back(&entry);

    std::sort(list.begin(),list.end(),[](auto& entry1, auto& entry2)
                                      {
                                        return entry1->second > entry2->second;
                                      });

    for (std::size_t i = 0 ; i <std::min(_top,list.size()) ; ++i)
      std::cout << list[i]->first << std::endl;
  }

  PrintMostFrequent(std::size_t top)
    : _top(top)
  {}

private:

  std::size_t _top;

};

#endif // PLUGIN_HH
