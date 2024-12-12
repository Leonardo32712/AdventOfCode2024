#include <map>

typedef long long long2;
typedef std::pair<long2, int> keyLongInt;

class Solutions {
    private:
        std::map<keyLongInt, long2> solutions;

    public:
        Solutions();
        ~Solutions();

        long2 getResult(long2, int);
        void saveResult(long2, int, long2);
};
