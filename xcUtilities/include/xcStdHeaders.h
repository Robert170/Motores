/**
 * @class xcStdHeaders
 *
 * @brief class for
 *
 * This class is to use the pointers of texture that directx needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 19/02/2021
 *
 *
 * @bug	No know Bugs
 */
#pragma once

 /*****************************************************************************/
  /*
  * C type objects
  */
  /*****************************************************************************/
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdarg>


/*****************************************************************************/
/*
* Memory management
*/
/*****************************************************************************/
#include <memory>

/*****************************************************************************/
/**
 *Containers includes
 */
 /*****************************************************************************/
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <list>
#include <forward_list>
#include <deque>
#include <queue>
#include <bitset>
#include <array>
#include <unordered_map>
#include <unordered_set>

/*****************************************************************************/
/*
* STL algorithms and functions
*/
/*****************************************************************************/
#include <algorithm>
#include <functional>
#include <limits>
#include <iterator>
#include <numeric>


/*****************************************************************************/
/**
 * Stream includes
 */
 /*****************************************************************************/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <filesystem>


//#include <windows.h>


namespace xcEngineSDK {

  /**
   * @brief using name Vector to our engine
   */
  template<typename T, typename A = std::allocator<T>>
  using Vector = std::vector<T, A>;

  /**
   * @brief using name Stack to our engine
   */
  template<typename T, typename A = std::allocator<T>>
  using Stack = std::stack <T,std::deque<T, A>>;

  /**
   * @brief using name ForwardList to our engine
   */
  template<typename T, typename A = std::allocator<T>>
  using ForwardList = std::forward_list<T, A>;

  /**
   * @brief using name Map to our engine
   */
  template <typename K,
            typename T,
            typename P = std::less<K>,
            typename A = std::allocator<std::pair<K, T>>>

  using Map = std::map<K, T, P, A>;

  /**
   * @brief using name MultiSet to our engine
   */
  template<typename T, 
           typename P = std::less<T>, 
           typename A = std::allocator<T>>
  using MultiSet = std::multiset<T, P, A>;

  /**
   * @brief using name MultiMap to our engine
   */
  template<typename K, 
           typename V, 
           typename P = std::less<K>, 
           typename A = std::allocator<std::pair<const K, V>>>
  using MultiMap = std::multimap<K, V, P, A>;

  /**
   * @brief using name set to our engine
   */
   template <typename T,
             typename P = std::less<T>,
             typename A = std::allocator<T>>

   using Set = std::set<T,P,A>;

  /**
   * @brief using name List to our engine
   */
  template<typename T, typename A = std::allocator<T>>
  using List = std::list<T, A>;

  /**
   * @brief using name Queue to our engine
   */
  template<typename T, typename A = std::allocator<T>>
  using Queue = std::queue<T, std::deque<T, A>>;

  /**
   * @brief using name Deque to our engine
   */
  template<typename T, typename A = std::allocator<T>>
  using Deque = std::deque<T, A>;

  /**
   * @brief using name String to our engine
   */
  using String = std::string;

  /**
   * @brief using name WString to our engine
   */
  using WString = std::wstring;

  /**
   * @brief using name IFstream to our engine
   */
  using IFstream = std::ifstream;

  /**
   * @brief using name OFstream to our engine
   */
  using OFstream = std::ofstream;

  /**
   * @brief using name Fstream to our engine
   */
  using Fstream = std::fstream;

  

  /**
   * @brief using name SPtr to our engine for smart pointer
   */
  template <typename T>
  using SPtr = std::shared_ptr<T>;

  /**
   * @brief using name WeakSptr to our engine for weak pointer
   */
  template <typename T>
  using WeakSptr = std::weak_ptr<T>;

  /**
   * @brief using name UPtr to our engine for unique pointer
   */
  template <typename T>
  using UPtr = std::unique_ptr<T>;

  namespace fsys = std::filesystem;

  using Path = std::filesystem::path;


}