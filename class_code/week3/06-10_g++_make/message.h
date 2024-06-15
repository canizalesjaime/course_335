#include<string>

class Message
{
    private:
        std::string message;

    public:
        void setMessage(std::string mess);
        std::string getMessage();
};