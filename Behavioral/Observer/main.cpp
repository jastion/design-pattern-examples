/**
 * Observer Design Pattern
 *
 * Intent: Lets you define a subscription mechanism to notify multiple objects
 * about any events that happen to the object they're observing.
 *
 * Note that there's a lot of different terms with similar meaning associated
 * with this pattern. Just remember that the Subject is also called the
 * Publisher and the Observer is often called the Subscriber and vice versa.
 * Also the verbs "observe", "listen" or "track" usually mean the same thing.
 */

#include <iostream>
#include <list>
#include <string>

using namespace std;

class BaseObserver {
    public:
        virtual ~BaseObserver(){};
        virtual void Update(const string& message_from_subject) = 0;
};

class BaseSubject {
    public:
        virtual ~BaseSubject(){};
        virtual void Attach(BaseObserver* observer) = 0;  
        virtual void Detach(BaseObserver* observer) = 0;
        virtual void Notify() = 0;
};

/**
 * The Subject owns some important state and notifies observers when the state
 * changes.
 */

class Subject : public BaseSubject {
    private:
        list<BaseObserver*> list_observer_;
        string message_;
    public:
        virtual ~Subject() {
            cout << "Goodbye, I was the subject" << endl;
        }

    /**
     * The subscription management methods.
     */

    void Attach(BaseObserver* observer) override {
        list_observer_.push_back(observer);
    }

    void Detach(BaseObserver* observer) override {
        list_observer_.remove(observer);
    }
    void Notify() override {
        list<BaseObserver*>::iterator iterator = list_observer_.begin();
        HowManyObserver();
        while (iterator != list_observer_.end()) {
            (*iterator)->Update(message_);
            ++iterator;
        }
    }

    void CreateMessage(string message = "Empty") {
        this->message_ = message;
        Notify();
    }


    void HowManyObserver() {
        cout << "There are " << list_observer_.size() << " observers in the list." << endl;
    }

    void SomeBusinessLogic() {
        this->message_ = "Change message message";
        Notify();
        cout << "I'm about to do something important" << endl;
    }
};

class Observer : public BaseObserver {
    private:
        string message_from_subject_;
        Subject &subject_;
        static int static_number_;
        int number_;

    public:
        Observer(Subject &subject) : subject_(subject) {
            this->subject_.Attach(this);
            cout << "Hi, I'm the observer \"" << ++Observer::static_number_ << "\"." << endl;
            this->number_ = Observer::static_number_;
        }
        virtual ~Observer() {
            cout << "Goodbye, I was the Observer \"" << this->number_ << "\"." << endl;
        }
        void Update(const string &message_from_subject) override {
            message_from_subject_ = message_from_subject;
            PrintInfo();
        }
        void RemoveMeFromTheList() {
            subject_.Detach(this);
            std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
        }
        void PrintInfo() {
            std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
        }

};

int Observer::static_number_ = 0;

void ClientCode() {
    Subject *subject = new Subject;
    Observer *observer1 = new Observer(*subject);
    Observer *observer2 = new Observer(*subject);
    Observer *observer3 = new Observer(*subject);
    Observer *observer4;
    Observer *observer5;

    subject->CreateMessage("Hello World!");
    observer3->RemoveMeFromTheList();

    subject->CreateMessage("The weather is hot today...");
    observer4 = new Observer(*subject);

    observer2->RemoveMeFromTheList();
    observer5 = new Observer(*subject);

    subject->CreateMessage("It's super cold now!");
    observer5->RemoveMeFromTheList();
    observer4->RemoveMeFromTheList();
    observer1->RemoveMeFromTheList();

    delete observer5;
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
    delete subject;

}

int main() {
    ClientCode();
    return 0;
}