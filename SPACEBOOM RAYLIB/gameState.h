#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameManager;
class MenuState;
class PlayState;

class GameState {
public:
    virtual ~GameState() {};
    virtual void handleInput(GameManager* context) = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};
#endif

/*
#include <iostream>
#include <boost/shared_ptr.hpp> // por boost::shared_ptr
using namespace std;

class State
{
public:
virtual ~State() {}
	void Action() { DoSomething(); }
private:
	virtual void DoSomething() = 0;
};

class ConcreteStateA : public State
{
private:
	void DoSomething() { cout << "ConcreteStateA: DoSomething" << endl; }
};

class ConcreteStateB : public State
{
private:
	void DoSomething() { cout << "ConcreteStateB: DoSomething" << endl; }
};
    
class Context
{
public:
	Context():currentState( new ConcreteStateA ) {}
    
	void SetState( State * newState )
	{
		currentState.reset( newState );
	}
    
	void DoSomething() { currentState->Action(); }
        
private:
	boost::shared_ptr<State> currentState;
};

int main()
{
	Context context;
	context.SetState( new ConcreteStateA );
	context.DoSomething();
	context.SetState( new ConcreteStateB );
	context.DoSomething();
	// ...

	cin.get();
}
*/