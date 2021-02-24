class Solution {

public:
	int sumDigits(int n) {
		int sum = 0;
		while (n) {
			sum += n % 10;
			n = n / 10;
		}
		return sum;
	}

	int RulingPair(vector<int> arr, int n){
		unordered_map<int, vector<int> > compatibles;
		for (auto ability : arr) {
			compatibles[sumDigits(ability)].push_back(ability);
		}
		int p1, p2, global_max = -1;
		for (auto c : compatibles) {
			if (c.second.size() >= 2) {
				int cp1 = c.second.at(0);
				int cp2 = c.second.at(1);
				int local_max = cp1 + cp2;
				for (size_t i = 2; i < c.second.size(); i++) {
					int cp = c.second.at(i);
					if (cp1 > cp2) {
						if (cp > cp2) {
							local_max += cp - cp2;
							cp2 = cp;
						}
					}
					else {
						if (cp > cp1) {
							local_max += cp - cp1;
							cp1 = cp;
						}
					}
				}
				if (local_max > global_max) {
					global_max = local_max;
					p1 = cp1;
					p2 = cp2;
				}
			}
		}

		return global_max;
	}
};