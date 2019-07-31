//
// Created by GH on 2018/11/25.
//

#ifndef GH_CODE_GH_H
#define GH_CODE_GH_H

#include <iostream>
#include <sys/time.h>
#include <fstream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;
namespace gh{
    void print();
    template <typename T, typename... Types>
    void print(const T& firstArg, const Types&... args)
    {
        std::cout<<firstArg<<" ";
        print(args...);
    }

    double current_time();

    std::string get_datetime();

    void executeCMD(const char *cmd, char *result);

    template <typename returnType, typename func, typename... args>
    returnType functime(func _func, args... _args) {
        double time1 = gh::current_time();
        returnType returnType1 = _func(_args...);
        double time2 = gh::current_time();
        gh::print("function time: ", time2 - time1);
        return returnType1;
    }


    template <typename func, typename... args>
    void functime(func _func, args... _args) {
        double time1 = gh::current_time();
        _func(_args...);
        double time2 = gh::current_time();
        gh::print("function time: ", time2 - time1);
    }
    std::list<std::string> split(const std::string& str, const std::string& delim);

    void *memoryCopy(const void *pSrc, void *pdest, int length);

    void visitVtbl(int **vtbl, int count);

    int strcmp(const char *st1, const char *st2);

    char* ghstrcpy(char *src, char *dest);

    char *strcat(char *dest, const char* src);

    class GHsingle{
    public:
        static GHsingle *getInstance() {
            if (gHsingle == nullptr)
                gHsingle = new GHsingle;
            return gHsingle;
        }
    private:
        static GHsingle *gHsingle;
        GHsingle() { std::cout<<"ghSingle create"<<std::endl;};
    };

    class LRUCache {
    public:
        LRUCache(int capacity): _cap(capacity){

        }

        int get(int key) {
            int resValue = -1;
            auto item = _cacheMap.find(key);
            if (item != _cacheMap.end()) {
                resValue = item->second->second;
                auto del = item->second;
                pair<int, int> temp = make_pair(key, resValue);
                _caches.erase(del);
                _caches.emplace_front(temp);
                _cacheMap[key] = _caches.begin();
            }
            return resValue;
        }

        void put(int key, int value) {
            auto item = _cacheMap.find(key);
            // already have
            if (item != _cacheMap.end()) {
                auto del = item->second;
                pair<int, int> temp = make_pair(key, value);
                _caches.erase(del);
                _caches.emplace_front(temp);
                _cacheMap[key] = _caches.begin();
            } else { //not have
                if (_caches.size() >= _cap) {
                    int delKey = _caches.back().first;
                    _cacheMap.erase(delKey);
                    _caches.pop_back();
                }
                pair<int, int> temp = make_pair(key, value);
                _caches.emplace_front(temp);
                _cacheMap[key] = _caches.begin();
            }
        }

    private:
        list<pair<int, int>> _caches;
        unordered_map<int, list<pair<int, int>>::iterator> _cacheMap;
        int _cap;
    };


}

#endif //GH_CODE_GH_H
