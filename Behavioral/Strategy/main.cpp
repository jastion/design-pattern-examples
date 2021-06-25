#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/**
 * The Strategy interface declares operations common to all supported versions
 * of some algorithm.
 *
 * The Context uses this interface to call the algorithm defined by Concrete
 * Strategies.
 */

class Strategy {
    public:
        virtual ~Strategy() {}
        virtual string DoAlgorithm(const vector<string> &data) const = 0;
};

/**
 * The Context defines the interface of interest to clients.
 */
class Context {
    private:
        Strategy *strategy_;
    public:
        Context(Strategy* strategy = nullptr) : strategy_(strategy) {}
        ~Context() {
            delete this->strategy_;
        }
        void set_strategy(Strategy *strategy) {
            delete this->strategy_;
            this->strategy_ = strategy;
        }

        void DoSomeBusinessLogic() const {
            cout << "Context: Sorting data using strategy (not sure yet)" << endl;
            string result = this->strategy_->DoAlgorithm(vector<string>({"a", "e", "c", "b", "d"}));
            cout << result << endl;
        }
};

class ConcreteStrategyA: public Strategy {
    public:
    string DoAlgorithm(const vector<string> &data) const override {
        string result;
        for_each(data.begin(), data.end(), [&result](const string &letter) {
            result += letter;
        });
        sort(result.begin(), result.end());
        return result;
    }
};

class ConcreteStrategyB: public Strategy {
    public:
    string DoAlgorithm(const vector<string> &data) const override {
        string result;
        for_each(data.begin(), data.end(), [&result](const string &letter) {
            result += letter;
        });
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size() / 2; ++i) {
            swap(result[i], result[result.size() - i - 1]);
        }
        return result;
    }
};
/**
 * The client code picks a concrete strategy and passes it to the context. The
 * client should be aware of the differences between strategies in order to make
 * the right choice.
 */
void ClientCode() {
    Context *context = new Context(new ConcreteStrategyA);
    cout << "Client: Strategy set to normal sorting" << endl;
    context->DoSomeBusinessLogic();
    cout << endl;
    cout << "Client: Strategy now using reverse sorting" << endl;
    context->set_strategy(new ConcreteStrategyB);
    context->DoSomeBusinessLogic();
    delete context;
}

int main() {
    ClientCode();
    return 0;
}