#include<bits/stdc++.h>
using namespace std;

int count_anagrams(char* str, char* text) {
    int counts[26]= {0}, countT[26]={0}, i = 0, lenS = 0, lenT = 0, ans = 0, front = -1, rear = -1;
    //count len of str
    while(*(str+lenS))
        lenS++;
    //count len of text
    while(*(text+lenT))
        lenT++;
    //keep count of individual letters that occured in string str in array count
    for(i=0; i<lenS; i++)
        counts[*(str+i) - 'a']++;
    //front and rear are two variables that point to the two indices front and rear such that
    //front-rear <= len always holds and whenever front-rear == len and also the count of alphabet at indices front in
    //text in countT(count array for text) is equal to count of that letter in count array and front-rear==length of str we get one of the answers.
    for(i=0; i<lenT; i++) {
        front++;
        countT[*(text+front) - 'a']++;
        if(counts[*(text+front) - 'a'] == countT[*(text+front) - 'a']) {
            if(front-rear == lenS) {
                ans++;
                rear++;
                countT[*(text+rear) - 'a']--;
            }
        }
        else if(counts[*(text+front) - 'a'] > countT[*(text+front) - 'a']){
            if(front-rear<lenS){

            }else{
                rear++;
                countT[*(text+rear) - 'a']--;
            }
        }
        else {
            while(*(text+rear+1) != *(text+front)) {
                rear++;
                countT[*(text+rear) - 'a']--;
            }
            rear++;
            countT[*(text+rear) - 'a']--;
        }
    }
    return ans;
}
//driver function
int main(void) {
    cout<<count_anagrams("for", "forofxroxfffor");
    return 0;
}
