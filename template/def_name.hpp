#pragma once
#include "template/header.hpp"

#define pb        push_back
#define eb        emplace_back
#define SZ(x)     ((int)(x).size())
#define all(x)    (x).begin(), (x).end()
#define rall(x)   (x).rbegin(), (x).rend()
#define popcnt(x) __builtin_popcountll(x)
template<class T = int>
using V = std::vector<T>;
template<class T = int>
using VV = std::vector<std::vector<T>>;
template<class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;
using int128 = __int128_t;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;