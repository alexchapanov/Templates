#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class
class Instrument
{
protected:
    string name;
    string sound;

public:
    Instrument(string n, string s)
    {
        name = n;
        sound = s;
    }

    virtual void play()
    {
        cout << name << ": " << sound << endl;
    }

    virtual ~Instrument() {}
};

// Derived classes

class Trumpet : public Instrument
{
public:
    Trumpet() : Instrument("Trumpet", "doot") {}

    void play() override
    {
        cout << name << ": ";
        for (int i = 0; i < 3; i++)
            cout << sound << " ";
        cout << endl;
    }
};

class Violin : public Instrument
{
public:
    Violin() : Instrument("Violin", "vwa") {}

    void play() override
    {
        cout << name << ": ";
        for (int i = 0; i < 5; i++)
            cout << sound << " ";
        cout << endl;
    }
};

class Piano : public Instrument
{
public:
    Piano() : Instrument("Piano", "Dee") {}

    void play() override
    {
        cout << name << ": ";
        for (int i = 0; i < 2; i++)
            cout << sound << " ";
        cout << endl;
    }
};

class Trombone : public Instrument
{
public:
    Trombone() : Instrument("Trombone", "Dwooooo~") {}

    void play() override
    {
        cout << name << ": " << sound << endl;
    }
};

class Singer : public Instrument
{
public:
    Singer() : Instrument("Singer", "Blah") {}

    void play() override
    {
        cout << name << ": ";
        for (int i = 0; i < 6; i++)
            cout << sound << " ";
        cout << endl;
    }
};

// Orchestra class
class Orchestra
{
private:
    vector<Instrument*> instruments;

public:
    void addInstrument(Instrument* inst)
    {
        instruments.push_back(inst);
    }

    void play()
    {
        for (Instrument* inst : instruments)
        {
            inst->play();
        }
    }

    ~Orchestra()
    {
        for (Instrument* inst : instruments)
        {
            delete inst;
        }
    }
};

int main()
{
    Orchestra orchestra;

    orchestra.addInstrument(new Trumpet());
    orchestra.addInstrument(new Violin());
    orchestra.addInstrument(new Piano());
    orchestra.addInstrument(new Trombone());
    orchestra.addInstrument(new Trumpet());
    orchestra.addInstrument(new Singer());

    orchestra.play();

    return 0;
}