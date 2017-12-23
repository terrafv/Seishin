#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Card
{
public:
    Card();
    Card(string _face, string _suit, int _value);
    Card(const Card & _card);
    ~Card();

    string getFace() const;
    string getSuit() const;
    int getValue() const;

    void setFace(const string _face);
    void setSuit(const string _suit);
    void setValue(const int _value);

    void print() const;
    int compare(const Card &c) const;

private:
    string face;
    string suit;
    int value;
};

Card::Card()
{
    face = "";
    suit = "";
    value = 0;
}

Card::Card(string _face, string _suit, int _value)
{
    face = _face;
    suit = _suit;
    value = _value;
}

Card::Card(const Card & _card)
{
    face = _card.face;
    suit = _card.suit;
    value = _card.value;
}

Card::~Card()
{

}

string Card::getFace() const
{
    return face;
}

string Card::getSuit() const
{
    return suit;
}

int Card::getValue() const
{
    return value;
}

void Card::setFace(const string _face)
{
    face = _face;
}

void Card::setSuit(const string _suit)
{
    suit = _suit;
}

void Card::setValue(const int _value)
{
    value = _value;
}

void Card::print() const
{
    cout << face << " of " << suit << " (" << value << " p)";
}

int Card::compare(const Card &c) const
{
    int f1 = value;
    int f2 = c.value;

    //Map J, Q, K, A to numerical values
    if (face == "J")
        f1 = 11;
    else if (face == "Q")
        f1 = 12;
    else if (face == "K")
        f1 = 13;
    else if (face == "A")
        f1 = 14;

    if (c.face == "J")
        f2 = 11;
    else if (c.face == "Q")
        f2 = 12;
    else if (c.face == "K")
        f2 = 13;
    else if (c.face == "A")
        f2 = 14;

    if (suit == c.suit)
    {
        if (f1 == f2)
            return 0;
        else if (f1 > f2)
            return -1;
        else
            return 1;
    }

    else if (suit > c.suit)
        return -1;

    else
        return 1;
}

void print(vector<Card> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << "\n\t";
        v[i].print();
    }
    cout << "\n\n";
}

int computeScore(vector<Card> v)
{
    int sum = 0;

    for (int i = 0; i < v.size(); i++)
        sum += v[i].getValue();

    return sum;
}

bool downgradeAce(vector<Card> &v, int &score)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].getValue() == 11)
        {
            v[i].setValue(1);
            score = computeScore(v);
            return true;
        }
    }

    return false;
}

void shuffle(vector<Card> &v)
{
    int c1;
    int c2;
    Card temp;

    srand(time(0));

    for (int i = 0; i < 100; i++)
    {
        c1 = rand() % v.size();
        c2 = rand() % v.size();

        temp = v[c1];
        v[c1] = v[c2];
        v[c2] = temp;
    }
}

void bubblesort(vector<Card> &v)
{
    Card temp;

    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - 1; j++)
        {
            if (v[j].compare(v[j+1]) == -1)         //Numbers are out of order
            {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp; //j q k a....a j k q
            }
        }
    }
}

int main()
{
    string suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    string faces[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int values[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

    vector<Card> deck;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            Card temp(faces[j], suits[i], values[j]);
            deck.push_back(temp);
        }
    }

    print(deck);

    shuffle(deck);
    cout << "\n\n";
    print(deck);

    vector<Card> player;
    vector<Card> dealer;
    int turnNumber = 1;

    //Deal 4 cards
    player.push_back(deck.back());
    deck.pop_back();

    dealer.push_back(deck.back());
    deck.pop_back();

    player.push_back(deck.back());
    deck.pop_back();

    dealer.push_back(deck.back());
    deck.pop_back();

    char option = ' ';
    int playerScore = computeScore(player);
    int dealerScore = computeScore(dealer);

    //Player hits until done
    do{
        while (playerScore > 21)
        {
            if (!downgradeAce(player, playerScore))
                break;
        }

        if (playerScore > 21)
        {
            cout << "Player:\n\t";
            print(player);
            cout << "Dealer:\n\t";
            dealer[0].print();
            cout << "\n\t???\n";
            cout << "\nBust! You have " << playerScore << " points. Game over.\n";
            return 0;
        }

        cout << "\n\n----------------[Turn " << turnNumber << "]----------------\n";
        cout << "Player:\n\t";
        print(player);
        cout << "Dealer:\n\t";
        dealer[0].print();
        cout << "\n\t???\n";

        cout << "\nYou have " << playerScore << " points.\n";
        cout << "What would you like to do? (H = hit, S = stay, B = bubblesort)\n";
        cin >> option;

        if (option == 'H')
        {
            player.push_back(deck.back());
            deck.pop_back();
            playerScore = computeScore(player);
        }
        else if (option == 'B')
        {
            bubblesort(player);
            continue;
        }

        turnNumber++;

    }while(option != 'S');

    //Print the hands
    cout << "\n\n-------[Turn " << turnNumber << "] (Dealer flips face-down card)-------\n";
    cout << "Player:\n\t";
    print(player);
    cout << "Dealer:\n\t";
    print(dealer);

    cout << "Dealer has " << dealerScore << " points\n";
    cout << "Player has " << playerScore << " points\n";

    //Dealer hits until 17
    while (dealerScore <= 16)
    {
        turnNumber++;
        cout << "\n\n----------------[Turn " << turnNumber << "] (Dealer hits)----------------\n";

        dealer.push_back(deck.back());
        deck.pop_back();
        dealerScore = computeScore(dealer);

        while (dealerScore > 21)
        {
            if (!downgradeAce(dealer, dealerScore))
                break;
        }

        cout << "Player:\n\t";
        print(player);
        cout << "Dealer:\n\t";
        print(dealer);

        cout << "Dealer has " << dealerScore << " points\n";
        cout << "Player has " << playerScore << " points\n";

        if (dealerScore > 21)
        {
            cout << "Dealer busts. You win!\n";
            return 0;
        }
    }

    turnNumber++;
    cout << "\n\n----------------[Turn " << turnNumber << "] (Dealer stays)----------------\n";
    cout << "Player:\n\t";
    print(player);
    cout << "Dealer:\n\t";
    print(dealer);

    cout << "Dealer has " << dealerScore << " points\n";
    cout << "Player has " << playerScore << " points\n";

    if (dealerScore > playerScore)
        cout << "Dealer wins\n";
    else if (dealerScore < playerScore)
        cout << "You win!\n";
    else
        cout << "Draw\n";

    return 0;
}
