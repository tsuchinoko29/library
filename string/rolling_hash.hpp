#pragma once
#include "template/header.hpp"

template <typename T>
struct rolling_hash {
   private:
	int n;
	const long long mod = (1ll << 61) - 1;
	long long base;
	std::vector<long long> hash, power;

	long long mul(long long x, long long y) const {
		return (__int128_t)x * y % mod;
	}

   public:
	rolling_hash() = default;

	rolling_hash(const T &s) : n((int)s.size()) {
		base = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		hash.assign(n + 1, 0);
		power.assign(n + 1, 1);
		for(int i = 0; i < n; i++) {
			hash[i + 1] = (mul(hash[i], base) + s[i]) % mod;
			power[i + 1] = (mul(power[i], base)) % mod;
		}
	}

	// get hash [l, r)
	long long get(const int l, const int r) const {
		assert(l < r and l >= 0 and r <= n);
		long long res = hash[r] - mul(hash[l], power[r - l]) % mod;
		if(res < 0) res += mod;
		return res;
	}

	// get hash [0, n)
	long long get_all() const { return get(0, n); }

	//[a, n) と[b, n)の最長共通接頭辞の長さを取得
	int get_lcp(const int a, const int b) const {
		assert(a >= 0 and a < n and b >= 0 and b < n);
		int len = std::min(n - a, n - b), ok = 0, ng = len;
		while(ng - ok > 1) {
			int mid = (ok + ng) / 2;
			if(get(a, a + mid) != get(b, b + mid))
				ng = mid;
			else
				ok = mid;
		}
		return ok;
	}
};
