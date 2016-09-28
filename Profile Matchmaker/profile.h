#ifndef _PROFILE
#define _PROFILE
#include <fstream>
#include <string>
#include<iostream>

using namespace std;

class Profile {
private:
	string name, username;
	int hairChoice, movieChoice, musicChoice, gameChoice, sportsChoice, score;
	static string question1[5];
	static string question2[5];
	static string question3[5];
public:
	Profile(){ username = "", name = "", hairChoice = -1, movieChoice = -1, musicChoice = -1, gameChoice = -1, sportsChoice = -1, score = -1; }
	~Profile(){};

	void setProfile(string, string, int, int, int, int, int);
	void setUsername(string u){ username = u; }
	void setName(string n){ name = n; }
	void setHair(int h) { hairChoice = h; }
	void setMovie(int m) { movieChoice = m; }
	void setMusic(int m) { musicChoice = m; }
	void setGameInterest(int g) { gameChoice = g; }
	void setSportsInterest(int s) { sportsChoice = s; }
	void setScore(int s) { score = s; }

	void getProfile();
	string getUsername(){ return username; }
	string getName(){ return name; }
	int getHair(){ return hairChoice; }
	int getMovie(){ return movieChoice; }
	int getMusic(){ return musicChoice; }
	int getGameInterest(){ return gameChoice; }
	int getSportsInterest(){ return sportsChoice; }
	int getScore(){ return score; }

	bool operator < (Profile &rightObj);
	void operator = (Profile &rightObj);
	bool operator == (Profile &rightObj);
	bool operator != (Profile &rightObj);

	friend fstream &operator >> (fstream &strm, Profile &obj);
	friend fstream &operator << (fstream &strm, Profile &obj);
	friend istream &operator >> (istream &strm, Profile &obj);
	friend ostream &operator << (ostream &strm, Profile &obj);
	friend ostream &operator <<= (ostream &strm, Profile &obj);

};

string Profile::question1[5] = {
	"Black", "Blonde", "Brown", "Red", "Other"
};

string Profile::question2[5] = {
	"Comedy", "Action", "Horror", "Drama", "Adventure"
};

string Profile::question3[5] = {
	"Rap/Hiphop", "EDM", "Rock/Metal", "Country", "Pop"
};

void Profile::setProfile(string user, string str, int hair, int movie, int music, int game, int sport){
	setUsername(user);
	setName(str);
	setHair(hair);
	setMovie(movie);
	setMusic(music);
	setGameInterest(game);
	setSportsInterest(sport);
	setScore(hair + movie * 10 + music * 100 + game * 1000 + sport * 10000);
}

void Profile::getProfile(){
	cout << "Username: " << username << endl
		<< "Full name: " << name << endl
		<< "Favorite hair color: " << question1[hairChoice] << endl
		<< "Favorite movie genre: " << question2[movieChoice] << endl
		<< "Favorite music genre: " << question3[musicChoice] << endl
		<< "Video game interest: " << gameChoice + 1 << "/5" << endl
		<< "Sports interest: " << sportsChoice + 1 << "/5" << endl << endl;
}

bool Profile::operator < (Profile &rightObj)
{
	if (score < rightObj.getScore())
		return 1;
	else
		return 0;

}

void Profile::operator = (Profile &rightObj){
	username = rightObj.username;
	name = rightObj.name;
	hairChoice = rightObj.hairChoice;
	movieChoice = rightObj.movieChoice;
	musicChoice = rightObj.musicChoice;
	gameChoice = rightObj.gameChoice;
	sportsChoice = rightObj.sportsChoice;
	score = rightObj.score;
}

bool Profile::operator == (Profile &rightObj){
	if (username == rightObj.username)
		return 1;
	else
		return 0;

}

bool Profile::operator != (Profile &rightObj){
	if (username != rightObj.username)
		return 1;
	else
		return 0;

}

fstream &operator >> (fstream &strm, Profile &obj)
{
	string info;
	int scoreTotal = 0;

	getline(strm, info, ',');
	obj.setUsername(info);

	getline(strm, info, ',');
	obj.setName(info);

	getline(strm, info, ',');
	obj.setHair(atoi(info.c_str()));
	scoreTotal += atoi(info.c_str());

	getline(strm, info, ',');
	obj.setMovie(atoi(info.c_str()));
	scoreTotal += atoi(info.c_str()) * 10;

	getline(strm, info, ',');
	obj.setMusic(atoi(info.c_str()));
	scoreTotal += atoi(info.c_str()) * 100;

	getline(strm, info, ',');
	obj.setGameInterest(atoi(info.c_str()));
	scoreTotal += atoi(info.c_str()) * 1000;

	getline(strm, info, '\n');
	obj.setSportsInterest(atoi(info.c_str()));
	scoreTotal += atoi(info.c_str()) * 10000;

	obj.setScore(scoreTotal);

	return strm;
}

fstream &operator << (fstream &strm, Profile &obj)
{
	strm << obj.username << ',' << obj.name << "," << obj.hairChoice << ","
		<< obj.movieChoice << "," << obj.musicChoice << "," << obj.gameChoice
		<< ',' << obj.sportsChoice << endl;
	return strm;
}

ostream &operator << (ostream &strm, Profile &obj)
{

	strm << "Username: " << obj.username << endl
		<< "Full name: " << obj.name << endl
		<< "Favorite hair color: " << obj.question1[obj.hairChoice - 1] << endl
		<< "Favorite movie genre: " << obj.question2[obj.movieChoice - 1] << endl
		<< "Favorite music genre: " << obj.question3[obj.musicChoice - 1] << endl
		<< "Video game interest: " << obj.gameChoice << "/5" << endl
		<< "Sports interest: " << obj.sportsChoice << "/5" << endl
		<< "Profile score: " << obj.score << endl << endl;

	return strm;
}

ostream &operator <<= (ostream &strm, Profile &obj)
{
	strm << obj.score;

	return strm;
}

istream &operator >> (istream &strm, Profile &obj)
{
	string info;
	obj.score = 0;

	//cout << "\nENTER USERNAME: ";
	cout << "\nEnter a username: ";
	cin.sync();
	cin.clear();
	getline(strm, info, '\n');
	obj.setUsername(info);

	//cout << "\nENTER FULLNAME: ";
	cout << "\nEnter your full name: ";
	cin.sync();
	cin.clear();
	getline(strm, info, '\n');
	obj.setName(info);

	int i = 0;
	cout << endl;
	while (obj.question1[i] != "")
		cout << i << ")." << obj.question1[i++] << endl;
	//cout << "\nENTER Favorite Hair: ";
	cout << "\nWhat is the most attractive hair color to you? ";
	cin.sync();
	cin.clear();

	bool fail = true;
	while (fail){
		try {
			cin.clear();
			cin >> obj.hairChoice;
			if (cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw "Invalid input. Enter an integer: ";
			}
			else if (obj.hairChoice < 1 || obj.hairChoice > 5)
				throw "Invalid input. Please enter a number from 1 to 5: ";
			else
				fail = false;
		}
		catch (char* error) {
			cout << error;
		}
	}

	obj.score += obj.hairChoice;

	i = 0;
	cout << endl;
	while (obj.question2[i] != "")
		cout << i << ")." << obj.question2[i++] << endl;
	//cout << "\nENTER  Favorite Movie Genre: ";
	cout << "\nWhat is your favorite genre of movies? ";
	cin.sync();
	cin.clear();

	fail = true;
	while (fail){
		try {
			cin.clear();
			cin >> obj.movieChoice;
			if (cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw "Invalid input. Enter an integer: ";
			}
			else if (obj.movieChoice < 1 || obj.movieChoice > 5)
				throw "Invalid input. Please enter a number from 1 to 5: ";
			else
				fail = false;
		}
		catch (char* error) {
			cout << error;
		}
	}

	obj.score += obj.movieChoice * 10;

	i = 0;
	cout << endl;
	while (obj.question1[i] != "")
		cout << i << ")." << obj.question3[i++] << endl;
	//cout << "\nENTER Favorite Music Genre: ";
	cout << "\nWhat is your favorite genre of music? ";
	cin.sync();
	cin.clear();

	fail = true;
	while (fail){
		try {
			cin.clear();
			cin >> obj.musicChoice;
			if (cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw "Invalid input. Enter an integer: ";
			}
			else if (obj.musicChoice < 1 || obj.musicChoice > 5)
				throw "Invalid input. Please enter a number from 1 to 5: ";
			else
				fail = false;
		}
		catch (char* error) {
			cout << error;
		}
	}

	obj.score += obj.musicChoice * 100;

	//cout << "\nENTER Video Game Interest [1 to 5]: ";
	cout << "\nHow interested are you in video games on a scale from 1-5: ";
	cin.sync();
	cin.clear();

	fail = true;
	while (fail){
		try {
			cin.clear();
			cin >> obj.gameChoice;
			if (cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw "Invalid input. Enter an integer: ";
			}
			else if (obj.gameChoice < 1 || obj.gameChoice > 5)
				throw "Invalid input. Please enter a number from 1 to 5: ";
			else
				fail = false;
		}
		catch (char* error) {
			cout << error;
		}
	}

	obj.score += obj.gameChoice * 1000;

	//cout << "\nENTER Sports Interest [1 to 5]: ";
	cout << "\nHow interested are you in sports on a scale from 1-5: ";
	cin.sync();
	cin.clear();

	fail = true;
	while (fail){
		try {
			cin.clear();
			cin >> obj.sportsChoice;
			if (cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw "Invalid input. Enter an integer: ";
			}
			else if (obj.sportsChoice < 1 || obj.sportsChoice > 5)
				throw "Invalid input. Please enter a number from 1 to 5: ";
			else
				fail = false;
		}
		catch (char* error) {
			cout << error;
		}
	}
	fail = true;
	obj.score += obj.sportsChoice * 10000;
	return strm;
}
#endif