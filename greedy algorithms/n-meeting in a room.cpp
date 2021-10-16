
// N- meeting question
//Greedy Algorithm
//Find maximun number of meetings
//There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
//What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

//Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

/*
Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct meeting{
    int start,end,pos;
};

bool comparator(struct meeting m1, meeting m2){
    if(m1.end < m2.end) return true;
    else if(m1.end>m2.end) return false;
    else if(m1.pos <m2.pos) return true;
    return false;
}

void maxMeeting(int s[],int e[],int n){
    struct meeting meet[n];
    for(int i=0;i<n;i++){
        meet[i].start=s[i];
        meet[i].end=e[i];
        meet[i].pos=i+1;
    }
    
    sort(meet, meet+n, comparator);
    
    int limit=meet[0].end;
    
    vector<int>answers;
    answers.push_back(meet[0].pos);
    for(int i=1;i<n;i++){
        if(meet[i].start > limit){
            limit=meet[i].end;
            answers.push_back(meet[i].pos);
        }
        
    }
    for(int i=0;i<answers.size();i++){
        cout<<answers[i]<<" ";
    }
}


int main(){
    int n;
    cin>>n;
    int s[n],f[n];  // s->start , f->finish
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    maxMeeting(s,f,n);
}

