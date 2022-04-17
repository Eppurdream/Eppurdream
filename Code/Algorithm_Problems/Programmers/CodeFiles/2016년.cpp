#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    int mouths[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string weeks[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
    int mouthCount = 1;
    int dayCount = 1;
    int weekCount = 4;
    bool exit = false;
    
    for (int i = 0; i < 12; i++)
    {
        for (int n = 0; n < mouths[i]; n++)
        {
            if (weekCount > 6)
            {
                weekCount = 0;
            }
            if (mouthCount == a && dayCount == b)
            {
                answer = weeks[weekCount];
                exit = true;
                break;
            }
            dayCount++;
            weekCount++;
        }
        
        if(exit) break;
        
        mouthCount++;
        dayCount = 1;
    }
    
    return answer;
}