#include "List.h"

Node::Node() {} // Node default constructor

Node::Node(string data) // Node parameterized constructor
{
    this->data = data;
}

List::List() // List default constructor
{
    head = new Node();
    tail = new Node();

    head->next = tail;
    tail->prev = head;
}

Node List::getNodebyId(int id)
{
    Node *temp = new Node();
    temp = head;

    while (temp != tail)
    {
        if (temp->id == id)
            return *temp;

        temp = temp->next;
    }

    Node *noNode = new Node();
    noNode->data = "Node with ID of " + to_string(id) + " does not exist";
    return *noNode;
}

void List::insertNode(string data, Node *p)
{
    Node *temp = new Node(data);

    temp->next = p->next;
    temp->prev = p;

    p->next->prev = temp;
    p->next = temp;

    setIds();
}

void List::insertNodeById(int id, string data)
{
    if (!List::empty())
    {
        Node node = getNodebyId(id);
        insertNode(data, node.next->prev);
    }
    else
    {
        cout << WHITE << "Whoops, list seems to be empty" << RESET << endl;
    }
}

void List::push_front(string data)
{
    insertNode(data, head);
}

void List::push_back(string data)
{
    insertNode(data, tail->prev);
}

void List::deleteNode(Node *p)
{
    if (!p || p == head || p == tail)
        return;

    p->next->prev = p->prev;
    p->prev->next = p->next;
    delete p;

    setIds();
}

void List::deleteNodeById(int id)
{
    if (!List::empty())
    {
        Node node = getNodebyId(id);
        deleteNode(node.next->prev);

        cout << WHITE << "The movie with an id of " << id << " has been deleted!" << RESET << endl;
    }
    else
    {
        cout << WHITE << "Whoops, there seems to be nothing to delete..." << RESET << endl;
    }
}

void List::deleteAllNodes()
{
    Node *temp = new Node();
    temp = head;

    if (!List::empty())
    {
        while (temp != tail)
        {
            deleteNode(temp);
            temp = temp->next;
        }

        cout << WHITE << "All movies deleted!" << RESET << endl;
    }
    else
    {
        cout << WHITE << "Whoops, there seems to be nothing to delete..." << RESET << endl;
    }
}

void List::setIds()
{
    int id = 0;
    Node *temp = new Node();
    temp = head;

    while (temp != tail)
    {
        temp->id = id++;
        temp = temp->next;
    }
}

void List::size()
{
    int count = 0;

    Node *temp = new Node();
    temp = head;

    while (temp->next != tail)
    {
        count++;
        temp = temp->next;
    }

    if (count == 1)
    {
        cout << WHITE << count << " movie in here!" << RESET << endl;
    }
    else
    {
        cout << WHITE << count << " movies in here!" << RESET << endl;
    }
}

void List::sort()
{
    if (!List::empty())
    {
        Node *i;
        Node *j;
        string temp;

        for (i = head; i->next != tail; i = i->next)
        {
            for (j = i->next; j->next != tail; j = j->next)
            {
                if (i->data > j->data)
                {
                    temp = j->data;
                    j->data = i->data;
                    i->data = temp;
                }
            }
        }

        cout << WHITE << "Your movies have been sorted! :)" << RESET << endl;
    }
    else
    {
        cout << WHITE << "Whoops, there seems to be nothing here to sort..." << RESET << endl;
    }
};

bool List::empty()
{
    return (head->next == tail);
}

void List::print()
{
    Node *temp = new Node();
    temp = head;

    if (!empty())
    {
        while (temp->next != tail)
        {
            cout << WHITE << temp->next->id << RESET << ". ";
            cout << WHITE << temp->next->data << RESET << endl;

            temp = temp->next;
        }
    }
    else
    {
        cout << WHITE << "List is empty" << RESET << endl;
    }
}

void List::printNodeById(int id)
{
    if (List::empty())
    {
        cout << WHITE << "List is empty" << RESET << endl;

        return;
    }

    Node node = getNodebyId(id);

    cout << WHITE << node.data << RESET << endl;
}

void List::saveToFile(string fileName)
{
    // Creates a .txt file
    // -------------------
    Node *temp = new Node();
    temp = head;

    ofstream file(fileName);

    while (temp->next != tail)
    {
        file << temp->next->data << endl;

        temp = temp->next;
    }

    file.close();

    // OR

    // Creates a .json file
    // --------------------
    // Node *temp = new Node();
    // temp = head;

    // ofstream file(fileName);
    // Json::Value object;
    // Json::Value array(Json::arrayValue);

    // while (temp->next != tail)
    // {
    //     array.append(Json::Value(temp->next->data));
    //     temp = temp->next;
    // }

    // object["movies"] = array;
    // file << object;

    // file.close();
}

string List::removeQuotes(string string)
{
    string.erase(
        remove(string.begin(), string.end(), '\"'),
        string.end());

    return string;
}

void List::loadFromFile(string fileName)
{
    ifstream file(fileName);

    // Reads from a .txt file
    // --------------------
    string movie;
    while (file >> movie)
    {
        List::push_back(movie);
    }

    // Reads from a .json file
    // --------------------
    // Json::Value json;
    // Json::Reader reader;

    // reader.parse(file, json);

    // for (int i = 0; i < json["movies"].size(); i++)
    // {
    //     string stringifiedMovie = json["movies"][i].asString();
    //     List::push_back(stringifiedMovie);
    // }
}

void List::displayCommands()
{
    cout << "----------------------------------------" << endl;
    cout << "1. Add a new movie" << endl;
    cout << "2. Add a new movie in a specific location" << endl;
    cout << "3. Display all my movies" << endl;
    cout << "4. Find a movie by ID" << endl;
    cout << "5. Delete all my movies" << endl;
    cout << "6. Delete a movie by ID" << endl;
    cout << "7. Sort my movies" << endl;
    cout << "8. Export my movies" << endl;
    cout << "9. Import my movies" << endl;
    cout << "10. Uhhh, how many movies do I have again?" << endl;
    cout << "----------------------------------------" << endl;
    cout << YELLOW << "11. Display commands" << YELLOW << endl;
    cout << RED << "12. Get me out of here!" << RESET << endl;
    cout << "----------------------------------------" << endl;
}

void List::success()
{
    cout << "----------------------------------------" << endl;
    cout << GREEN << "Operation executed successfully!" << RESET << endl;
    cout << GREEN << "What'd you like to do now? " << RESET << endl;
    cout << "----------------------------------------" << endl;
}

void List::runProgram()
{
    cout << GREEN << "Welcome back, Netflix Admin..." << RESET << endl;
    cout << GREEN << "What'd you like to do today?" << RESET << endl;

    displayCommands();

    int input;

    do
    {
        cin >> input;

        string movie;
        int id;
        switch (input)
        {
        case 1:
            cout << "----------------------------------------" << endl;
            cout << "Enter movie name: ";
            getline(cin >> ws, movie);
            List::push_back(movie);
            List::success();
            break;

        case 2:
            cout << "----------------------------------------" << endl;
            cout << "Enter movie name: ";
            getline(cin >> ws, movie);
            cout << "Enter the ID to which you want to insert your movie after: ";
            cin >> id;
            List::insertNodeById(id, movie);
            List::success();
            break;

        case 3:
            cout << "----------------------------------------" << endl;
            List::print();
            List::success();
            break;

        case 4:
            cout << "----------------------------------------" << endl;
            cout << "Enter the ID of the movie you're lookin' for: ";
            cin >> id;
            cout << "----------------------------------------" << endl;
            List::printNodeById(id);
            List::success();
            break;

        case 5:
            cout << "----------------------------------------" << endl;
            List::deleteAllNodes();
            List::success();
            break;

        case 6:
            cout << "----------------------------------------" << endl;
            cout << "Enter the ID of the movie you wanna delete: ";
            cin >> id;
            cout << "----------------------------------------" << endl;
            List::deleteNodeById(id);
            List::success();
            break;

        case 7:
            cout << "----------------------------------------" << endl;
            List::sort();
            List::success();
            break;

        case 8:
            cout << "----------------------------------------" << endl;
            cout << "What'd you like to name your file as? ";
            getline(cin >> ws, movie);
            List::saveToFile(movie);
            List::success();
            break;

        case 9:
            cout << "----------------------------------------" << endl;
            cout << "What's the name of the file from which you wanna import yo movies? ";
            getline(cin >> ws, movie);
            List::loadFromFile(movie);
            List::success();
            break;

        case 10:
            cout << "----------------------------------------" << endl;
            List::size();
            List::success();
            break;

        case 11:
            displayCommands();
            break;

        case 12:
            break;

        default:
            cout << "----------------------------------------" << endl;
            cout << RED << "Oops, command is out of scope; are you trying to exit? Try 12" << RESET << endl;
            cout << "----------------------------------------" << endl;
            break;
        }
    } while (input != 12);
}
