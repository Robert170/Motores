#pragma once

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
/**
 * Stream includes
 */
 /*****************************************************************************/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

namespace xcEngineSDK {

  /**
   * @brief using name Vector to our engine
   */
  template<typename T, typename A>
  using Vector = std::vector<T, A>;

  /**
   * @brief using name Stack to our engine
   */
  template<typename T, typename A>
  using Stack = std::stack <T,std::deque<T, A>>;

  /**
   * @brief using name Map to our engine
   */
  template <typename K,
            typename T,
            typename P = std::less<K>,
            typename A = std::pair<K, T>>

  using Map = std::map<K, T, P, A>;

  /**
   * @brief using name set to our engine
   */
   /*template <typename T,
             typename P = std::less<T>,
             typename A = std::allocator<T>>

   using Set = std::set<T,P,A>;*/

  /**
   * @brief using name list to our engine
   */
  template<typename T, typename A>
  using List = std::list<T, A>;
}