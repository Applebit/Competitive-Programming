//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<map>
#include<vector>
#include<stdio.h>
#include<string.h>
#include <algorithm>
typedef std::vector<int> vi;

using namespace std;




int main(){
    int tc;
    scanf("%d", &tc);
    while (tc--){

        int candidateNumber;
        int voterNumber;
        scanf("%d %d", &candidateNumber,&voterNumber);
        vector< vi > voterPreferencesList(voterNumber, vi(candidateNumber));
        map<int, int> countVotes;
        for (int i = 0; i < voterNumber; i++)
        {
            for (int j = 0;  j < candidateNumber; j++)
            {
                scanf("%d", &voterPreferencesList[i][j]);
                if (j == 0)
                {
                    countVotes[voterPreferencesList[i][j]]++;   //Count the number of votes
                }
            }
        }
        
        vector< pair<int, int> > getMaxVotes;
        for (map<int, int>::iterator it = countVotes.begin(); it != countVotes.end(); ++it)
        {
            getMaxVotes.push_back(make_pair(it->second, it->first));
        }
        sort(getMaxVotes.rbegin(), getMaxVotes.rend()); //reverse sort the pair so we could get the top contestent at the very top of Array
        int votesNeedToWin = voterNumber / 2 + 1;
        int round = 1;
        if (getMaxVotes[0].first >= votesNeedToWin || getMaxVotes.size()==1)
        {
            printf("%d %d\n", getMaxVotes[0].second,round);
        }
        else
        {
            vi firstTwo;
            round++;
            firstTwo.push_back(getMaxVotes[0].second);
            firstTwo.push_back(getMaxVotes[1].second);
            int countfirst = 0, countSecond = 0;
            for (int i = 0; i < voterPreferencesList.size(); i++)
            {
                for (int j = 0; j < voterPreferencesList[i].size(); j++)
                {
                    if (voterPreferencesList[i][j] == firstTwo[0])
                    {
                        countfirst++;
                        break;
                    }
                    else if (voterPreferencesList[i][j] == firstTwo[1])
                    {
                        countSecond++;
                        break;
                    }
                }
            }
            if (countfirst > countSecond)
                printf("%d %d\n", firstTwo[0],round);
            else
                printf("%d %d\n", firstTwo[1],round);
        }
        
    }
return 0;
}