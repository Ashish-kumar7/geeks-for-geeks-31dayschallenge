class Solution{
    public:
    	int min_sprinklers(int gal[], int n)
		{
			vector<pair<int, int>> sprinkle;
			for(int i = 0;i < n;i++)
			{
				if(gal[i] > -1)
					sprinkle.push_back(pair<int, int> (i - gal[i], i + gal[i]));
			}

			sort(sprinkle.begin(), sprinkle.end());

			int tar = 0, sprinkle_active = 0, i = 0;
			while(tar < n)
			{
				if(i == sprinkle.size() || sprinkle[i].first > tar)
					return -1;

				int range = sprinkle[i].second;
				while(i + 1 < sprinkle.size() && sprinkle[i + 1].first <= tar)
				{
					i++;
					range = max(range, sprinkle[i].second);
				}

				if(range < tar)
					return -1;
				sprinkle_active++;
				tar = range + 1;
				i++;
			}
			return sprinkle_active;
		}
};
