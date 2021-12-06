#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Track{
private:
    double id;
    string name;
public:
    Track(double id,string name) :id(id),name(name){}
    void print() const{
        cout<<"Track "<<id<<": "<<name<<"\n";
    }
};

class Playlist{
private:
    string name;
    list<Track*> tracks;
public:
    Playlist(string name):name(name){}
    void addTrack(Track *track){
        tracks.push_back(track);
    }
    void removeTrack(Track *track){
        tracks.remove(track);
    }
    void play(){
        cout<<"Playing "<<name<<endl;
        for(list<Track*>::iterator i = tracks.begin(); i != tracks.end(); i++){
            (*i)->print();
        }
        cout<<"\n";
    }
};

class TrackDataBase{
private:
    vector<Track*> tracks;
    static double UUID;
public:
    void addTrack(string name) {
        tracks.push_back(new Track(UUID++, name));
    }
    Track* operator[](const int rhs){
        return tracks[rhs];
    }
    ~TrackDataBase(){
        for(vector<Track*>::iterator i = tracks.begin(); i != tracks.end(); i++)
        {
            delete *i;
        }
    }
};

double TrackDataBase::UUID = 0;

void Zadanie1();

int main()
{
    Zadanie1();

    TrackDataBase dataBase;
    dataBase.addTrack("Utwor 1");
    dataBase.addTrack("Utwor 2");
    dataBase.addTrack("Utwor 3");
    dataBase.addTrack("Utwor 4");

    Playlist list("Lista 1");
    list.addTrack(dataBase[1]);
    list.addTrack(dataBase[3]);
    list.addTrack(dataBase[0]);

    list.play();

    list.removeTrack(dataBase[3]);

    list.play();

    list.addTrack(dataBase[1]);
    list.addTrack(dataBase[1]);

    list.play();

    return 0;
}

void Zadanie1(){
    string napis = "Ala ma kota";
    cout<<"Before: "<<napis<<endl;
    for(string::iterator i = napis.begin(); i != napis.end(); i++)
    {
        if (*i >= 'a' && *i <= 'z') *i += 'A' - 'a';
    }
    cout<<"After: "<<napis<<endl;
}