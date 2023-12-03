// ZOO.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Animals {
private:
    string name_animal[3];
    string color_animal[3];
    int age_animal[3];
public:
    string animal[7];
    Animals();
    void add_animal(int a);
    void actoin(int a, int b) {
        if (a == 1) {
            if (b == 1) { cout << "You've chosen the action: Feed the lions." << endl; }
            if (b == 2) { cout << "You've chosen an action: Feed the elephants." << endl; }
            if (b == 3) { cout << "You've chosen an action: Feed the giraffes." << endl; }
            if (b == 4) { cout << "You've chosen an action: Feed the flamingos." << endl; }
        }
        else if (a == 2) {
            if (b == 1) { cout << "You've chosen to pet a lion." << endl; }
            if (b == 2) { cout << "You've chosen to pet an elephant." << endl; }
            if (b == 3) { cout << "You've chosen to pet a giraffe" << endl; }
            if (b == 4) { cout << "You've chosen to pet a  flamingo." << endl; }
        }

    }
    ;
    void remove_animal();
    void print_animal();
    void Restore();

};


Animals::Animals() {
    //cout << "At the moment, such animals are available in the zoo:" << endl;
    animal[0] = "lion"; animal[1] = "elephant"; animal[2] = "giraffe"; animal[3] = "flamingo";
    //cout << animal[0] << " " << animal[1] << " " << animal[2] << " " << animal[3] << "\n";

};

void Animals::Restore() {
    animal[0] = "lion"; animal[1] = "elephant"; animal[2] = "giraffe"; animal[3] = "flamingo"; animal[4] = ""; animal[5] = ""; animal[6] = "";
}
void Animals::add_animal(int a) {
    string anim;
    if (a > 0) {
        cout << "You want to add " << a << " animals. Write the animals you want to add."<<endl;
        for (int i = 1; i < a + 1; i++) {
            cin >> anim;
            animal[3 + i] = anim;
        }
        cout << "Now the zoo has:";
        for (int i = 0; i < a + 4; i++) {
            cout << animal[i] << "\n";
        }
    }

};
void Animals::remove_animal() {
    int a;
    cout << "1." << animal[0] << "       2." << animal[1] << "      3." << animal[2] << "        4." << animal[3] << "        5." << animal[4] << "       6." << animal[5] << "        7." << animal[6] << endl;
    cin >> a;
    for (int i = 0; i < 7; i++) {
        if (i == a - 1) { animal[i] = " "; }
    }
}
void Animals::print_animal(){
    cout << "At the moment, such animals are available in the zoo:" << endl;
    cout << animal[0] << "   " << animal[1] << "  " << animal[2] << "   " << animal[3] << "   " << animal[4] << "  " << animal[5] << "   " << animal[6] << endl;
}
//void Animals::actoin(int a, int b) {/*
//    if (a == 1) {
//        if (b == 1) { cout << "You approach a cage with lions. Thanks to the zookeeper, you manage to feed them safely. One of the lions seemed to smile, and the other shook his tail as a sign of gratitude."<<endl; }
//        if (b == 2) { cout << "You approach the cage with the elephants. Thanks to the zookeeper, you manage to feed them safely. One of the elephants raised its trunk and waved happily at you, while the other moved its ears in gratitude."<<endl; }
//        if (b == 3) { cout << "Giraffes look great today. You want to feed them, but when you give them food, they're just watching you. Today, they are not hungry."<<endl; }
//        if (b == 4) { cout<<"You are admiring the flamingos. You decide to feed them, but by accidentally making a loud noise, you scare them. They're flying away." << endl; }
//    }
//    else if (a == 2) {
//        if (b == 1) { cout << "You want to pet the lions, but the workers won't let you. One of them tells you how one day a lion bit off the finger of a man who wanted to stroke it." << endl; }
//         if (b == 2) { cout << "You've stroked the elephant's trunk. The elephant looks pleased and wags its tail." << endl; }*/
////         if (b == 3) { cout << "Giraffes are huge and beautiful. You want to pet them, but none of them come close to you." << endl; }
////         if (b == 4) { cout << "You are fascinated by flamingos. When you reach out to one of them, you touch its wing. But he flies away, frightened. There's a pink feather in your hand, and you're looking at it sadly." << endl; }
////    }
////    /*else if (a == 3) {
////        if (b == 1) { cout << "" << endl; }
//        else if (b == 2) { cout << "" << endl; }
//        else if (b == 3) { cout << "" << endl; }
//        else if (b == 4) { cout << "" << endl; }
//    }*/
//}

class Lion: public Animals {
private:
    string name_animal[3]{"Big Max", "Little Artemchik", "Lady Gaga"};
    int age_animal[3]{9, 1, 6};
    string color_animal[3]{ "yellow", "light brown", "yellow"};
public:
    Lion();
    void lgetname() { for (int i = 0; i < 3; i++) { cout << name_animal[i] << endl; } cout << endl; };
    void lgetage() { for (int i = 0; i < 3; i++) { cout << age_animal[i] << endl; } cout << endl;
    };
    void lgetcolor() { for (int i = 0; i < 3; i++) { cout << color_animal[i] << endl; 
    } cout << endl;};
    void actoin(int a, int b) {
        if (a == 1) {
            if (b == 1) { cout << "You approach a cage with lions. Thanks to the zookeeper, you manage to feed them safely. One of the lions seemed to smile, and the other shook his tail as a sign of gratitude." << endl; }
        }
        else if (a == 2) {
            if (b == 1) { cout << "You want to pet the lions, but the workers won't let you. One of them tells you how one day a lion bit off the finger of a man who wanted to stroke it." << endl; }
        }
    };
    void charac_lion() {
        cout << "NAME-AGE-FUR COLOR"<<endl;
        for (int i = 0; i < 3; i++) {
            cout<<"name: " << name_animal[i] << "  -  " << age_animal[i] << " ears  -  " << color_animal[i] << " fur" << endl;
        } cout << endl;
    }
};
Lion::Lion() {};

class Elephante: public Animals {
private:
    string name_animal[3]{"Limmi", "Ushastiy", "Dark Night"};
    int age_animal[3]{18, 9,40};
    string color_animal[3]{ "dark grey", "light grey", "dark grey"};
public:
    Elephante();
    void egetname() { for (int i = 0; i < 3; i++) { cout << name_animal[i] << endl; } cout << endl; };
    void egetage() { for (int i = 0; i < 3; i++) { cout << age_animal[i] << endl; } cout << endl;
    };
    void egetcolor() { for (int i = 0; i < 3; i++) { cout << color_animal[i] << endl; 
    } cout << endl;};
    void actoin(int a, int b) {
        if (a == 1) {
            if (b == 2) { cout << "You approach the cage with the elephants. Thanks to the zookeeper, you manage to feed them safely. One of the elephants raised its trunk and waved happily at you, while the other moved its ears in gratitude." << endl; }   
        }
        else if (a == 2) {
            if (b == 2) { cout << "You've stroked the elephant's trunk. The elephant looks pleased and wags its tail." << endl; }
        }
    };
    void charac_elephante() {
        cout << "NAME-AGE-FUR COLOR"<<endl;
        for (int i = 0; i < 3; i++) {
            cout<<"name: " << name_animal[i] << "  -  " << age_animal[i] << " ears  -  " << color_animal[i] << " fur" << endl;
        } cout << endl;
    }
};
Elephante::Elephante() {}

class Flamingo : public Animals {
private:
    string name_animal[3]{ "Miledi", "Missis White", "Mister White" };
    int age_animal[3]{38, 25, 25 };
    string color_animal[3]{ "pink", "white", "white" };
public:
    Flamingo();
    void fgetname() { for (int i = 0; i < 3; i++) { cout << name_animal[i] << endl; } cout << endl; };
    void fgetage() {
        for (int i = 0; i < 3; i++) { cout << age_animal[i] << endl; } cout << endl;
    };
    void fgetcolor() {
        for (int i = 0; i < 3; i++) {
            cout << color_animal[i] << endl;
        } cout << endl;
    };
    void actoin(int a, int b) {
        if (a == 1) {
            if (b == 4) { cout << "You are admiring the flamingos. You decide to feed them, but by accidentally making a loud noise, you scare them. They're flying away." << endl; }
        }
        else if (a == 4) {
            if (b == 2) { cout << "You are fascinated by flamingos. When you reach out to one of them, you touch its wing. But he flies away, frightened. There's a pink feather in your hand, and you're looking at it sadly." << endl;
            }
        }
    };
    void charac_flamingo() {
        cout << "NAME-AGE-FUR COLOR" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "name: " << name_animal[i] << "  -  " << age_animal[i] << " ears  -  " << color_animal[i] << " fur" << endl;
        } cout << endl;
    }
};
Flamingo::Flamingo() {}

class Giraffe : public Animals {
private:
    string name_animal[3]{ "Biggi", "Flower", "Lady Mimi" };
    int age_animal[3]{ 15, 7, 20 };
    string color_animal[3]{  "light brown","yellow with brown spots", "yellow" };
public:
    Giraffe();
    void ggetname() { for (int i = 0; i < 3; i++) { cout << name_animal[i] << endl; } cout << endl; };
    void ggetage() {
        for (int i = 0; i < 3; i++) { cout << age_animal[i] << endl; } cout << endl;
    };
    void ggetcolor() {
        for (int i = 0; i < 3; i++) {
            cout << color_animal[i] << endl;
        } cout << endl;
    };
    void actoin(int a, int b) {
        if (a == 1) {
            if (b == 3) { cout << "Giraffes look great today. You want to feed them, but when you give them food, they're just watching you. Today, they are not hungry.." << endl; }
        }
        else if (a == 3) {
            if (b == 2) {
                cout << "Giraffes are huge and beautiful. You want to pet them, but none of them come close to you..." << endl;
            }
        }
    };;
    void charac_giraffe() {
        cout << "NAME-AGE-FUR COLOR" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "name: " << name_animal[i] << "  -  " << age_animal[i] << " ears  -  " << color_animal[i] << " fur" << endl;
        } cout << endl;
    }
};
Giraffe::Giraffe() {}

int main()
{
    int a;
    char out = 'n';
    int choise;
    int choise2;
    int choise3;
    cout << "Welcome to the zoo!" << endl;
        Animals animal; 
        animal.print_animal();
    while (out == 'n') {
        cout << "What do you want to do?" << "\n" << "1. Interact with animals." << "\n" << "2. Add an animal." << "\n" << "3. View all the animals."<<"\n"<<"4. Restore the Zoo (Remove all added animals)" << "\n";
        cin >> choise;
        if (choise == 1) {
            cout << "Select the animal you want to interact with (only a number)." << "\n" << "1. Lions" << "\n" << "2. Elephants" << "\n" << "3. Giraffes" << "\n" << "4. Flamingos" << endl;
            cin >> choise3;
            cout << "What do you want to do with the animal? (only a number)." << "\n" << "1. to feed" << "\n" << "2. to stroke" << "\n" << "3. to watch characteristic" << endl;
            cin >> choise2; //animal.actoin(choise2, choise3); }
            Lion l; Elephante e;  Giraffe g; Flamingo f; 
            if (choise2 == 1) {
                if (choise3 == 1) { animal.actoin(1, 1); l.actoin(1, 1); }
                if (choise3 == 2) { animal.actoin(1, 2); e.actoin(1, 2); }
                if (choise3 == 3) { animal.actoin(1, 3); g.actoin(1, 3); }
                if (choise3 == 4) { animal.actoin(1, 4); f.actoin(1, 4); }
            }
            else if (choise2 == 2) {
                if (choise3 == 1) { animal.actoin(2, 1); l.actoin(2, 1); }
                if (choise3 == 2) { animal.actoin(2, 2); e.actoin(2, 2); }
                if (choise3 == 3) { animal.actoin(2, 3); g.actoin(2, 3); }
                if (choise3 == 4) { animal.actoin(2, 4); f.actoin(2, 4); }
            }
            else if (choise2 == 3) {
                if (choise3 == 1) { cout << "Let's get to know our lion family better!" << endl; l.charac_lion(); }
                if (choise3 == 2) { cout << "Let's get to know our elephante family better!" << endl; e.charac_elephante(); }
                if (choise3 == 3) { cout << "Let's get to know our giraffe family better!" << endl; g.charac_giraffe(); }
                if (choise3 == 4) { cout << "Let's get to know our flamingo family better!" << endl; f.charac_flamingo(); }
            }
        }
        else if (choise == 2) {
            cout << "There are 4 species of animals in my zoo, do you want to add your own? There can be up to 7 animals in the zoo. There is not enough budget for a large zoo:(....Enter the quantity (max 3)" << endl;
            cin >> a;
            animal.add_animal(a);
        }
        else if (choise == 3) { animal.print_animal(); }
        else if (choise == 4) { animal.Restore(); animal.print_animal(); }
        cout << "Want to get out of the zoo? Print y/n" << "\n";
        cin >> out;
    }
}
//string animal_name[3];
//string animal_color[3];
//string animal_voice[3];
//string animal_skils[2];