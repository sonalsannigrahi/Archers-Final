#include<queue>
#include<iostream>

class GameFPS{
    private:
        std::queue<double> queue;
    public:
        GameFPS(){
            while (!queue.empty()) queue.pop();
        }

        void UpdateFPS(double elapsedTime){
            //std::cout << queue.size() << std::endl;
            //if (!queue.empty()) std::cout << elapsedTime << " " << queue.front() << std::endl;
            queue.push(elapsedTime);
            while (!queue.empty() && std::abs(elapsedTime - queue.front()) > 1.0) queue.pop();
        }

        int GetFPS(){
            return queue.size();
        }
};