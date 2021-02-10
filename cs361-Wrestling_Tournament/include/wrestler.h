#ifndef WRESTLER_H
#define WRESTLER_H


class wrestler
{
    public:
        wrestler();
        virtual ~wrestler();
        void setWeight(int var){weight=var;}
        int getWeight(){return weight;}
        void setId(int var){id=var;}
        int getId(){return id;}
        void setTeamId(int var){teamId=var;}
        int getTeamId(){return teamId;}
        void setAbility(int var){abilityScore=var;}
        int getAbility() const {return abilityScore;}
        bool const operator< (const wrestler& rhs)const
        {
            if(abilityScore == rhs.abilityScore){return abilityScore<rhs.abilityScore;}
            else return  !(abilityScore < rhs.abilityScore);
        }
    private:
        int weight;
        int id;
        int teamId;
        int abilityScore;
};

#endif // WRESTLER_H
