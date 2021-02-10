#include <iostream>
#include <ctime>
#include <list>
#include <vector>
#include <random>
#include <queue>
#include <fstream>
#include <bits/stdc++.h>
#include "include/wrestler.h"
#include "include/abilityCompare.h"
using namespace std;

int bout(wrestler * wr1, wrestler * wr2,default_random_engine * gptr);
int result(int score);
int main()
{
    ///initializing everything
    priority_queue<wrestler*, vector<wrestler*>, abilityCompare> wrestlerT100[14];
    priority_queue<wrestler*, vector<wrestler*>, abilityCompare> wrestlerT200[14];
    priority_queue<wrestler*, vector<wrestler*>, abilityCompare> wrestlerT300[14];
    priority_queue<wrestler*, vector<wrestler*>, abilityCompare> wrestlerT400[14];
    priority_queue<wrestler*, vector<wrestler*>, abilityCompare> wrestlerT500[14];
    priority_queue<wrestler*, vector<wrestler*>, abilityCompare> wrestlerT600[14];
    priority_queue<wrestler*, vector<wrestler*>, abilityCompare> wrestlerT700[14];
    priority_queue<wrestler*, vector<wrestler*>, abilityCompare> wrestlerT800[14];
    priority_queue<wrestler*, vector<wrestler*>, abilityCompare> bracketSeed[14];
    int score;
    int teamSize;
    int teamScore[8];
    int finalScore[8];
    int winnerTeam;
    for(int i=0;i<8;i++)
    {
        teamScore[i]=0;
    }
    fstream fout;
    fout.open("results.txt",ios::out);

    default_random_engine * gptr;
    gptr = new default_random_engine(time(NULL));
    normal_distribution<double> scoredist(100,15);
    normal_distribution<double> weightdist(157,20);
    normal_distribution<double> sizedist (28,5);
    wrestler * wptr;
    wrestler * wr[8];
    wrestler * winner;
    winner = NULL;
    wrestler * standings[8];
    wrestler * loser;
    loser = NULL;
    wrestler * bracketBout[2][14];

    ///this section creates wrestlers and sorts them into their teams, i probably could have done this better
    for(int i=1;i<=8;i++){
        teamSize=sizedist(*gptr);
        for(int j=1;j<=teamSize;j++)
        {
            wptr = new wrestler;
            wptr->setTeamId(100*i);
            wptr->setId(wptr->getTeamId()+j);
            wptr->setWeight(weightdist(*gptr));
            wptr->setAbility(scoredist(*gptr));
            if(wptr->getTeamId()==100){
                if(wptr->getWeight()<=106)
                    wrestlerT100[0].push(wptr);
                else if(wptr->getWeight()<=113)
                    wrestlerT100[1].push(wptr);
                else if(wptr->getWeight()<=120)
                    wrestlerT100[2].push(wptr);
                else if(wptr->getWeight()<=126)
                    wrestlerT100[3].push(wptr);
                else if(wptr->getWeight()<=132)
                    wrestlerT100[4].push(wptr);
                else if(wptr->getWeight()<=138)
                    wrestlerT100[5].push(wptr);
                else if(wptr->getWeight()<=145)
                    wrestlerT100[6].push(wptr);
                else if(wptr->getWeight()<=152)
                    wrestlerT100[7].push(wptr);
                else if(wptr->getWeight()<=160)
                    wrestlerT100[8].push(wptr);
                else if(wptr->getWeight()<=170)
                    wrestlerT100[9].push(wptr);
                else if(wptr->getWeight()<=182)
                    wrestlerT100[10].push(wptr);
                else if(wptr->getWeight()<=195)
                    wrestlerT100[11].push(wptr);
                else if(wptr->getWeight()<=220)
                    wrestlerT100[12].push(wptr);
                else if(wptr->getWeight()<=285)
                    wrestlerT100[13].push(wptr);
                }
            else if(wptr->getTeamId()==200){
                if(wptr->getWeight()<=106)
                    wrestlerT200[0].push(wptr);
                else if(wptr->getWeight()<=113)
                    wrestlerT200[1].push(wptr);
                else if(wptr->getWeight()<=120)
                    wrestlerT200[2].push(wptr);
                else if(wptr->getWeight()<=126)
                    wrestlerT200[3].push(wptr);
                else if(wptr->getWeight()<=132)
                    wrestlerT200[4].push(wptr);
                else if(wptr->getWeight()<=138)
                    wrestlerT200[5].push(wptr);
                else if(wptr->getWeight()<=145)
                    wrestlerT200[6].push(wptr);
                else if(wptr->getWeight()<=152)
                    wrestlerT200[7].push(wptr);
                else if(wptr->getWeight()<=160)
                    wrestlerT200[8].push(wptr);
                else if(wptr->getWeight()<=170)
                    wrestlerT200[9].push(wptr);
                else if(wptr->getWeight()<=182)
                    wrestlerT200[10].push(wptr);
                else if(wptr->getWeight()<=195)
                    wrestlerT200[11].push(wptr);
                else if(wptr->getWeight()<=220)
                    wrestlerT200[12].push(wptr);
                else if(wptr->getWeight()<=285)
                    wrestlerT200[13].push(wptr);
            }
            else if(wptr->getTeamId()==300){
                if(wptr->getWeight()<=106)
                    wrestlerT300[0].push(wptr);
                else if(wptr->getWeight()<=113)
                    wrestlerT300[1].push(wptr);
                else if(wptr->getWeight()<=120)
                    wrestlerT300[2].push(wptr);
                else if(wptr->getWeight()<=126)
                    wrestlerT300[3].push(wptr);
                else if(wptr->getWeight()<=132)
                    wrestlerT300[4].push(wptr);
                else if(wptr->getWeight()<=138)
                    wrestlerT300[5].push(wptr);
                else if(wptr->getWeight()<=145)
                    wrestlerT300[6].push(wptr);
                else if(wptr->getWeight()<=152)
                    wrestlerT300[7].push(wptr);
                else if(wptr->getWeight()<=160)
                    wrestlerT300[8].push(wptr);
                else if(wptr->getWeight()<=170)
                    wrestlerT300[9].push(wptr);
                else if(wptr->getWeight()<=182)
                    wrestlerT300[10].push(wptr);
                else if(wptr->getWeight()<=195)
                    wrestlerT300[11].push(wptr);
                else if(wptr->getWeight()<=220)
                    wrestlerT300[12].push(wptr);
                else if(wptr->getWeight()<=285)
                    wrestlerT300[13].push(wptr);
            }
            else if(wptr->getTeamId()==400){
                if(wptr->getWeight()<=106)
                    wrestlerT400[0].push(wptr);
                else if(wptr->getWeight()<=113)
                    wrestlerT400[1].push(wptr);
                else if(wptr->getWeight()<=120)
                    wrestlerT400[2].push(wptr);
                else if(wptr->getWeight()<=126)
                    wrestlerT400[3].push(wptr);
                else if(wptr->getWeight()<=132)
                    wrestlerT400[4].push(wptr);
                else if(wptr->getWeight()<=138)
                    wrestlerT400[5].push(wptr);
                else if(wptr->getWeight()<=145)
                    wrestlerT400[6].push(wptr);
                else if(wptr->getWeight()<=152)
                    wrestlerT400[7].push(wptr);
                else if(wptr->getWeight()<=160)
                    wrestlerT400[8].push(wptr);
                else if(wptr->getWeight()<=170)
                    wrestlerT400[9].push(wptr);
                else if(wptr->getWeight()<=182)
                    wrestlerT400[10].push(wptr);
                else if(wptr->getWeight()<=195)
                    wrestlerT400[11].push(wptr);
                else if(wptr->getWeight()<=220)
                    wrestlerT400[12].push(wptr);
                else if(wptr->getWeight()<=285)
                    wrestlerT400[13].push(wptr);
            }
            else if(wptr->getTeamId()==500){
                if(wptr->getWeight()<=106)
                    wrestlerT500[0].push(wptr);
                else if(wptr->getWeight()<=113)
                    wrestlerT500[1].push(wptr);
                else if(wptr->getWeight()<=120)
                    wrestlerT500[2].push(wptr);
                else if(wptr->getWeight()<=126)
                    wrestlerT500[3].push(wptr);
                else if(wptr->getWeight()<=132)
                    wrestlerT500[4].push(wptr);
                else if(wptr->getWeight()<=138)
                    wrestlerT500[5].push(wptr);
                else if(wptr->getWeight()<=145)
                    wrestlerT500[6].push(wptr);
                else if(wptr->getWeight()<=152)
                    wrestlerT500[7].push(wptr);
                else if(wptr->getWeight()<=160)
                    wrestlerT500[8].push(wptr);
                else if(wptr->getWeight()<=170)
                    wrestlerT500[9].push(wptr);
                else if(wptr->getWeight()<=182)
                    wrestlerT500[10].push(wptr);
                else if(wptr->getWeight()<=195)
                    wrestlerT500[11].push(wptr);
                else if(wptr->getWeight()<=220)
                    wrestlerT500[12].push(wptr);
                else if(wptr->getWeight()<=285)
                    wrestlerT500[13].push(wptr);
            }
            else if(wptr->getTeamId()==600){
                if(wptr->getWeight()<=106)
                    wrestlerT600[0].push(wptr);
                else if(wptr->getWeight()<=113)
                    wrestlerT600[1].push(wptr);
                else if(wptr->getWeight()<=120)
                    wrestlerT600[2].push(wptr);
                else if(wptr->getWeight()<=126)
                    wrestlerT600[3].push(wptr);
                else if(wptr->getWeight()<=132)
                    wrestlerT600[4].push(wptr);
                else if(wptr->getWeight()<=138)
                    wrestlerT600[5].push(wptr);
                else if(wptr->getWeight()<=145)
                    wrestlerT600[6].push(wptr);
                else if(wptr->getWeight()<=152)
                    wrestlerT600[7].push(wptr);
                else if(wptr->getWeight()<=160)
                    wrestlerT600[8].push(wptr);
                else if(wptr->getWeight()<=170)
                    wrestlerT600[9].push(wptr);
                else if(wptr->getWeight()<=182)
                    wrestlerT600[10].push(wptr);
                else if(wptr->getWeight()<=195)
                    wrestlerT600[11].push(wptr);
                else if(wptr->getWeight()<=220)
                    wrestlerT600[12].push(wptr);
                else if(wptr->getWeight()<=285)
                    wrestlerT600[13].push(wptr);
            }
            else if(wptr->getTeamId()==700){
                if(wptr->getWeight()<=106)
                    wrestlerT700[0].push(wptr);
                else if(wptr->getWeight()<=113)
                    wrestlerT700[1].push(wptr);
                else if(wptr->getWeight()<=120)
                    wrestlerT700[2].push(wptr);
                else if(wptr->getWeight()<=126)
                    wrestlerT700[3].push(wptr);
                else if(wptr->getWeight()<=132)
                    wrestlerT700[4].push(wptr);
                else if(wptr->getWeight()<=138)
                    wrestlerT700[5].push(wptr);
                else if(wptr->getWeight()<=145)
                    wrestlerT700[6].push(wptr);
                else if(wptr->getWeight()<=152)
                    wrestlerT700[7].push(wptr);
                else if(wptr->getWeight()<=160)
                    wrestlerT700[8].push(wptr);
                else if(wptr->getWeight()<=170)
                    wrestlerT700[9].push(wptr);
                else if(wptr->getWeight()<=182)
                    wrestlerT700[10].push(wptr);
                else if(wptr->getWeight()<=195)
                    wrestlerT700[11].push(wptr);
                else if(wptr->getWeight()<=220)
                    wrestlerT700[12].push(wptr);
                else if(wptr->getWeight()<=285)
                    wrestlerT700[13].push(wptr);
            }
            else if(wptr->getTeamId()==800){
                if(wptr->getWeight()<=106)
                    wrestlerT800[0].push(wptr);
                else if(wptr->getWeight()<=113)
                    wrestlerT800[1].push(wptr);
                else if(wptr->getWeight()<=120)
                    wrestlerT800[2].push(wptr);
                else if(wptr->getWeight()<=126)
                    wrestlerT800[3].push(wptr);
                else if(wptr->getWeight()<=132)
                    wrestlerT800[4].push(wptr);
                else if(wptr->getWeight()<=138)
                    wrestlerT800[5].push(wptr);
                else if(wptr->getWeight()<=145)
                    wrestlerT800[6].push(wptr);
                else if(wptr->getWeight()<=152)
                    wrestlerT800[7].push(wptr);
                else if(wptr->getWeight()<=160)
                    wrestlerT800[8].push(wptr);
                else if(wptr->getWeight()<=170)
                    wrestlerT800[9].push(wptr);
                else if(wptr->getWeight()<=182)
                    wrestlerT800[10].push(wptr);
                else if(wptr->getWeight()<=195)
                    wrestlerT800[11].push(wptr);
                else if(wptr->getWeight()<=220)
                    wrestlerT800[12].push(wptr);
                else if(wptr->getWeight()<=285)
                    wrestlerT800[13].push(wptr);
            }
        }
    }
    ///DONE CREATING WRESTLERS----------------------

    ///run a loop 14 times for each weight class, their brackets and score being added inside
    for(int i=0;i<14;i++)
    {
        fout<<"-----------------------------------------------\n";
        fout<<"Bracket for Weight Class ";
        ///fout statement declaring what weight class we are in
        switch(i)
        {
        case 0:
            fout<<"106\n\n";
            break;
        case 1:
            fout<<"113\n\n";
            break;
        case 2:
            fout<<"120\n\n";
            break;
        case 3:
            fout<<"126\n\n";
            break;
        case 4:
            fout<<"132\n\n";
            break;
        case 5:
            fout<<"138\n\n";
            break;
        case 6:
            fout<<"145\n\n";
            break;
        case 7:
            fout<<"152\n\n";
            break;
        case 8:
            fout<<"160\n\n";
            break;
        case 9:
            fout<<"170\n\n";
            break;
        case 10:
            fout<<"182\n\n";
            break;
        case 11:
            fout<<"195\n\n";
            break;
        case 12:
            fout<<"220\n\n";
            break;
        case 13:
            fout<<"285\n\n";
            break;

        }
        ///clear pointers
        for(int i=0;i<8;i++)
        {
            wr[i]=NULL;
            standings[i]=NULL;
        }

        for(int i=0;i<14;i++)
            bracketBout[0][i]=NULL;
        for(int i=0;i<14;i++)
            bracketBout[1][i]=NULL;

        ///put every wrestler from [i] weight class and put them in a priority queue to be properly sorted
        if(!wrestlerT100[i].empty())
        {
            bracketSeed[i].push(wrestlerT100[i].top());
        }
        if(!wrestlerT200[i].empty())
        {
            bracketSeed[i].push(wrestlerT200[i].top());
        }
        if(!wrestlerT300[i].empty())
        {
            bracketSeed[i].push(wrestlerT300[i].top());
        }
        if(!wrestlerT400[i].empty())
        {
            bracketSeed[i].push(wrestlerT400[i].top());
        }
        if(!wrestlerT500[i].empty())
        {
            bracketSeed[i].push(wrestlerT500[i].top());
        }
        if(!wrestlerT600[i].empty())
        {
            bracketSeed[i].push(wrestlerT600[i].top());
        }
        if(!wrestlerT700[i].empty())
        {
            bracketSeed[i].push(wrestlerT700[i].top());
        }
        if(!wrestlerT800[i].empty())
        {
            bracketSeed[i].push(wrestlerT800[i].top());
        }
        ///entire weight class of wrestlers is now in the priority queue sorted by ability score, funnel these wrestlers into their proper bracket spots



        int counter=0;
        while(!bracketSeed[i].empty())
        {
            wr[counter]=bracketSeed[i].top();
            bracketSeed[i].pop();
            counter++;
        }
        ///put wrestlers into 2 dimensional array, lhs and rhs are 0 and 1 or x & bouts are 0-14 or y
        bracketBout[0][0]=wr[0];
        bracketBout[1][0]=wr[7];
        bracketBout[0][1]=wr[3];
        bracketBout[1][1]=wr[4];
        bracketBout[0][2]=wr[1];
        bracketBout[1][2]=wr[6];
        bracketBout[0][3]=wr[2];
        bracketBout[1][3]=wr[5];

        ///THIS SECTION WILL BE REPEATED FOR EVERY BOUT AND THEN SHOW RESULTS
        if(bracketBout[0][0]==NULL&&bracketBout[1][0]==NULL)
        {
            fout<<"No wrestler available\n";
        }
        else if(bracketBout[1][0]==NULL&&bracketBout[0][0]>0)
        {
            winner=bracketBout[0][0];
            loser=bracketBout[1][0];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][0]==NULL&&bracketBout[0][0]>NULL)
        {
            winner=bracketBout[1][0];
            loser=bracketBout[0][0];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else
        {
            score=bout(bracketBout[0][0],bracketBout[1][0],gptr);
            if(score>=0)
            {
                winner=bracketBout[0][0];
                loser=bracketBout[1][0];
            }
            else
            {
                winner=bracketBout[1][0];
                loser=bracketBout[0][0];
            }
            fout<<"Wrestler "<<winner->getId()<<" beat wrestler "<<loser->getId()<<" with a score of "<<abs(score)<<endl;
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        bracketBout[0][4]=winner;
        bracketBout[0][6]=loser;
        winner=NULL;
        loser=NULL;
        ///___________________________________________________
        if(bracketBout[0][1]==NULL&&bracketBout[1][1]>0)
        {
            winner=bracketBout[1][1];
            loser=bracketBout[0][1];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][1]==NULL&&bracketBout[0][1]>0)
        {
            winner=bracketBout[0][1];
            loser=bracketBout[1][1];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][1]==NULL&&bracketBout[0][1]==NULL)
        {
            fout<<"No wrestler available\n";
        }
        else
        {
            score=bout(bracketBout[0][1],bracketBout[1][1],gptr);
            if(score>=0)
            {
                winner=bracketBout[0][1];
                loser=bracketBout[1][1];
            }
            else
            {
                winner=bracketBout[1][1];
                loser=bracketBout[0][1];
            }
            fout<<"Wrestler "<<winner->getId()<<" beat wrestler "<<loser->getId()<<" with a score of "<<abs(score)<<endl;
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        bracketBout[1][4]=winner;
        bracketBout[1][6]=loser;
        winner=NULL;
        loser=NULL;

        if(bracketBout[0][2]==NULL&&bracketBout[1][2]>0)
        {
            winner=bracketBout[1][2];
            loser=bracketBout[0][2];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][2]==NULL&&bracketBout[0][2]>0)
        {
            winner=bracketBout[0][2];
            loser=bracketBout[1][2];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][2]==NULL&&bracketBout[0][2]==NULL)
        {
            fout<<"No wrestler available\n";
        }
        else
        {
            score=bout(bracketBout[0][2],bracketBout[1][2],gptr);
            if(score>=0)
            {
                winner=bracketBout[0][2];
                loser=bracketBout[1][2];
            }
            else
            {
                winner=bracketBout[1][2];
                loser=bracketBout[0][2];
            }
            fout<<"Wrestler "<<winner->getId()<<" beat wrestler "<<loser->getId()<<" with a score of "<<abs(score)<<endl;
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        bracketBout[0][5]=winner;
        bracketBout[0][7]=loser;
        winner=NULL;
        loser=NULL;

        if(bracketBout[0][3]==NULL&&bracketBout[1][3]>0)
        {
            winner=bracketBout[1][3];
            loser=bracketBout[0][3];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][3]==NULL&&bracketBout[0][3]>0)
        {
            winner=bracketBout[0][3];
            loser=bracketBout[1][3];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][3]==NULL&&bracketBout[0][3]==NULL)
        {
            fout<<"No wrestler available\n";
        }
        else
        {
            score=bout(bracketBout[0][3],bracketBout[1][3],gptr);
            if(score>=0)
            {
                winner=bracketBout[0][3];
                loser=bracketBout[1][3];
            }
            else
            {
                winner=bracketBout[1][3];
                loser=bracketBout[0][3];
            }
            fout<<"Wrestler "<<winner->getId()<<" beat wrestler "<<loser->getId()<<" with a score of "<<abs(score)<<endl;
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        bracketBout[1][5]=winner;
        bracketBout[1][7]=loser;
        winner=NULL;
        loser=NULL;

        if(bracketBout[0][4]==NULL&&bracketBout[1][4]>0)
        {
            winner=bracketBout[1][4];
            loser=bracketBout[0][4];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][4]==NULL&&bracketBout[0][4]>0)
        {
            winner=bracketBout[0][4];
            loser=bracketBout[1][4];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][4]==NULL&&bracketBout[0][4]==NULL)
        {
            fout<<"No wrestler available\n";
        }
        else
        {
            score=bout(bracketBout[0][4],bracketBout[1][4],gptr);
            if(score>=0)
            {
                winner=bracketBout[0][4];
                loser=bracketBout[1][4];
            }
            else
            {
                winner=bracketBout[1][4];
                loser=bracketBout[0][4];
            }
            fout<<"Wrestler "<<winner->getId()<<" beat wrestler "<<loser->getId()<<" with a score of "<<abs(score)<<endl;
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        bracketBout[0][13]=winner;
        bracketBout[0][9]=loser;
        winner=NULL;
        loser=NULL;

        if(bracketBout[0][5]==NULL&&bracketBout[1][5]>0)
        {
            winner=bracketBout[1][5];
            loser=bracketBout[0][5];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][5]==NULL&&bracketBout[0][5]>0)
        {
            winner=bracketBout[0][5];
            loser=bracketBout[1][5];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][5]==NULL&&bracketBout[0][5]==NULL)
        {
            fout<<"No wrestler available\n";
        }
        else
        {
            score=bout(bracketBout[0][5],bracketBout[1][5],gptr);
            if(score>=0)
            {
                winner=bracketBout[0][5];
                loser=bracketBout[1][5];
            }
            else
            {
                winner=bracketBout[1][5];
                loser=bracketBout[0][5];
            }
            fout<<"Wrestler "<<winner->getId()<<" beat wrestler "<<loser->getId()<<" with a score of "<<abs(score)<<endl;
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        bracketBout[1][13]=winner;
        bracketBout[0][8]=loser;
        winner=NULL;
        loser=NULL;

        if(bracketBout[0][6]==NULL&&bracketBout[1][6]>0)
        {
            winner=bracketBout[1][6];
            loser=bracketBout[0][6];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][6]==NULL&&bracketBout[0][6]>0)
        {
            winner=bracketBout[0][6];
            loser=bracketBout[1][6];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][6]==NULL&&bracketBout[0][6]==NULL)
        {
            fout<<"No wrestler available\n";
        }
        else
        {
            score=bout(bracketBout[0][6],bracketBout[1][6],gptr);
            if(score>=0)
            {
                winner=bracketBout[0][6];
                loser=bracketBout[1][6];
            }
            else
            {
                winner=bracketBout[1][6];
                loser=bracketBout[0][6];
            }
            fout<<"Wrestler "<<winner->getId()<<" beat wrestler "<<loser->getId()<<" with a score of "<<abs(score)<<endl;
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        bracketBout[1][8]=winner;
        bracketBout[0][10]=loser;
        winner=NULL;
        loser=NULL;

        if(bracketBout[0][7]==NULL&&bracketBout[1][7]>0)
        {
            winner=bracketBout[1][7];
            loser=bracketBout[0][7];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][7]==NULL&&bracketBout[0][7]>0)
        {
            winner=bracketBout[0][7];
            loser=bracketBout[1][7];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][7]==NULL&&bracketBout[0][7]==NULL)
        {
            fout<<"No wrestler available\n";
        }
        else
        {
            score=bout(bracketBout[0][7],bracketBout[1][7],gptr);
            if(score>=0)
            {
                winner=bracketBout[0][7];
                loser=bracketBout[1][7];
            }
            else
            {
                winner=bracketBout[1][7];
                loser=bracketBout[0][7];
            }
            fout<<"Wrestler "<<winner->getId()<<" beat wrestler "<<loser->getId()<<" with a score of "<<abs(score)<<endl;
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        bracketBout[1][9]=winner;
        bracketBout[1][10]=loser;
        winner=NULL;
        loser=NULL;

        if(bracketBout[0][8]==NULL&&bracketBout[1][8]>0)
        {
            winner=bracketBout[1][8];
            loser=bracketBout[0][8];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][8]==NULL&&bracketBout[0][8]>0)
        {
            winner=bracketBout[0][8];
            loser=bracketBout[1][8];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][8]==NULL&&bracketBout[0][8]==NULL)
        {
            fout<<"No wrestler available\n";
        }
        else
        {
            score=bout(bracketBout[0][8],bracketBout[1][8],gptr);
            if(score>=0)
            {
                winner=bracketBout[0][8];
                loser=bracketBout[1][8];
            }
            else
            {
                winner=bracketBout[1][8];
                loser=bracketBout[0][8];
            }
            fout<<"Wrestler "<<winner->getId()<<" beat wrestler "<<loser->getId()<<" with a score of "<<abs(score)<<endl;
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        bracketBout[0][12]=winner;
        bracketBout[0][11]=loser;
        winner=NULL;
        loser=NULL;

        if(bracketBout[0][9]==NULL&&bracketBout[1][9]>0)
        {
            winner=bracketBout[1][9];
            loser=bracketBout[0][9];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][9]==NULL&&bracketBout[0][9]>0)
        {
            winner=bracketBout[0][9];
            loser=bracketBout[1][9];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][9]==NULL&&bracketBout[0][9]==NULL)
        {
            fout<<"No wrestler available\n";
        }
        else
        {
            score=bout(bracketBout[0][9],bracketBout[1][9],gptr);
            if(score>=0)
            {
                winner=bracketBout[0][9];
                loser=bracketBout[1][9];
            }
            else
            {
                winner=bracketBout[1][9];
                loser=bracketBout[0][9];
            }
            fout<<"Wrestler "<<winner->getId()<<" beat wrestler "<<loser->getId()<<" with a score of "<<abs(score)<<endl;
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        bracketBout[1][12]=winner;
        bracketBout[1][11]=loser;
        winner=NULL;
        loser=NULL;

        if(bracketBout[0][10]==NULL&&bracketBout[1][10]>0)
        {
            winner=bracketBout[1][10];
            loser=bracketBout[0][10];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][10]==NULL&&bracketBout[0][10]>0)
        {
            winner=bracketBout[0][10];
            loser=bracketBout[1][10];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][10]==NULL&&bracketBout[0][10]==NULL)
        {
            fout<<"No wrestler available\n";
        }
        else
        {
            score=bout(bracketBout[0][10],bracketBout[1][10],gptr);
            if(score>=0)
            {
                winner=bracketBout[0][10];
                loser=bracketBout[1][10];
            }
            else
            {
                winner=bracketBout[1][10];
                loser=bracketBout[0][10];
            }
            fout<<"Wrestler "<<winner->getId()<<" beat wrestler "<<loser->getId()<<" with a score of "<<abs(score)<<endl;
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        standings[6]=winner;
        standings[7]=loser;
        winner=NULL;
        loser=NULL;

        if(bracketBout[0][11]==NULL&&bracketBout[1][11]>0)
        {
            winner=bracketBout[1][11];
            loser=bracketBout[0][11];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][11]==NULL&&bracketBout[0][11]>0)
        {
            winner=bracketBout[0][11];
            loser=bracketBout[1][11];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][11]==NULL&&bracketBout[0][11]==NULL)
        {
            fout<<"No wrestler available\n";
        }
        else
        {
            score=bout(bracketBout[0][11],bracketBout[1][11],gptr);
            if(score>=0)
            {
                winner=bracketBout[0][11];
                loser=bracketBout[1][11];
            }
            else
            {
                winner=bracketBout[1][11];
                loser=bracketBout[0][11];
            }
            fout<<"Wrestler "<<winner->getId()<<" beat wrestler "<<loser->getId()<<" with a score of "<<abs(score)<<endl;
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        standings[4]=winner;
        standings[5]=loser;
        winner=NULL;
        loser=NULL;

        if(bracketBout[0][12]==NULL&&bracketBout[1][12]>0)
        {
            winner=bracketBout[1][12];
            loser=bracketBout[0][12];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][12]==NULL&&bracketBout[0][12]>0)
        {
            winner=bracketBout[0][12];
            loser=bracketBout[1][12];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][12]==NULL&&bracketBout[0][12]==NULL)
        {
            fout<<"No wrestler available\n";
        }
        else
        {
            score=bout(bracketBout[0][12],bracketBout[1][12],gptr);
            if(score>=0)
            {
                winner=bracketBout[0][12];
                loser=bracketBout[1][12];
            }
            else
            {
                winner=bracketBout[1][12];
                loser=bracketBout[0][12];
            }
            fout<<"Wrestler "<<winner->getId()<<" beat wrestler "<<loser->getId()<<" with a score of "<<abs(score)<<endl;
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        standings[2]=winner;
        standings[3]=loser;
        winner=NULL;
        loser=NULL;

        if(bracketBout[0][13]==NULL&&bracketBout[1][13]>0)
        {
            winner=bracketBout[1][13];
            loser=bracketBout[0][13];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][13]==NULL&&bracketBout[0][13]>0)
        {
            winner=bracketBout[0][13];
            loser=bracketBout[1][13];
            fout<<"Wrestler "<<winner->getId()<<" wins by default\n";
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        else if(bracketBout[1][13]==NULL&&bracketBout[0][13]==NULL)
        {
            fout<<"No wrestler available\n";
        }
        else
        {
            score=bout(bracketBout[0][13],bracketBout[1][13],gptr);
            if(score>=0)
            {
                winner=bracketBout[0][13];
                loser=bracketBout[1][13];
            }
            else
            {
                winner=bracketBout[1][13];
                loser=bracketBout[0][13];
            }
            fout<<"Wrestler "<<winner->getId()<<" beat wrestler "<<loser->getId()<<" with a score of "<<abs(score)<<endl;
            winnerTeam=(winner->getTeamId())/100;
            teamScore[winnerTeam]+=score;
        }
        standings[0]=winner;
        standings[1]=loser;
        winner=NULL;
        loser=NULL;

        ///AFTER ALL THAT STUFF we can now cout our standings
        ///switch for weight class (i now see i could have made a function but i did it so)
        cout<<"Weight class ";
        switch(i)
        {
        case 0:
            cout<<"106";
            break;
        case 1:
            cout<<"113";
            break;
        case 2:
            cout<<"120";
            break;
        case 3:
            cout<<"126";
            break;
        case 4:
            cout<<"132";
            break;
        case 5:
            cout<<"138";
            break;
        case 6:
            cout<<"145";
            break;
        case 7:
            cout<<"152";
            break;
        case 8:
            cout<<"160";
            break;
        case 9:
            cout<<"170";
            break;
        case 10:
            cout<<"182";
            break;
        case 11:
            cout<<"195";
            break;
        case 12:
            cout<<"220";
            break;
        case 13:
            cout<<"285";
            break;
        }
        cout<<" results\n";

        if(standings[0]==NULL)
        {
            cout<<"This bracket was empty\n";
        }
        else
        {
            cout<<"1st "<<standings[0]->getId()<<endl;
            if(standings[1]==NULL)
            {
                cout<<"No other wrestlers in this bracket\n";
            }
            else
            {
                cout<<"2nd "<<standings[1]->getId()<<endl;
                if(standings[2]==NULL)
                {
                    cout<<"No other wrestlers in this bracket\n";
                }
                else
                {
                    cout<<"3rd "<<standings[2]->getId()<<endl;
                }
            }
        }

        cout<<"------------------------------------------------------"<<endl;
    }

    ///sort the array to get the top score
    for(int i=0;i<8;i++)
        finalScore[i]=teamScore[i];
    int temp=0;
    for(int i=0;i<8;i++)
	{
		for(int j=i+1;j<8;j++)
		{
			if(teamScore[i]<teamScore[j])
			{
				temp  =teamScore[i];
				teamScore[i]=teamScore[j];
				teamScore[j]=temp;
			}
		}
	}
    ///now print final results of the tournament
    cout<<"\nFINAL RESULTS\n1st - Team ";
    for(int i=0;i<8;i++)
    {
        if(finalScore[i]==teamScore[0])
        {
            cout<<i*100;
            break;
        }
    }
    cout<<" with a score of "<<teamScore[0]<<"\n2nd - Team ";
    for(int i=0;i<8;i++)
    {
        if(finalScore[i]==teamScore[1])
        {
            cout<<i*100;
            break;
        }
    }
    cout<<" with a score of "<<teamScore[1]<<"\n3rd - Team ";
    for(int i=0;i<8;i++)
    {
        if(finalScore[i]==teamScore[2])
        {
            cout<<i*100;
            break;
        }
    }
    cout<<" with a score of "<<teamScore[2];
    fout.close();
    return 0;
}
int bout(wrestler * wr1, wrestler * wr2,default_random_engine * gptr)
{
    int score;
    score=wr1->getAbility() - wr2->getAbility();

    if(score>=0)
    {
        if (score <= 7)
            {score=2;}
        else if (score <= 11)
            {score=3;}
        else if (score <= 14)
            {score=4;}
        else if (score <= 18)
            {score=5;}
        else
            {score=6;}
    }
    else if (score<0)
    {
        score=abs(score);
        if (score <= 7)
            {score=-2;}
        else if (score <= 11)
            {score=-3;}
        else if (score <= 14)
            {score=-4;}
        else if (score <= 18)
            {score=-5;}
        else
            {score=-6;}

    }

    return score;
}
