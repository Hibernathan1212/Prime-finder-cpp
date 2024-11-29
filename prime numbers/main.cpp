#include <iostream>

#include <fstream>
#include <vector>

void prime_finder(const uint64_t limit)
{
    std::chrono::time_point<std::chrono::system_clock> start;
    start = std::chrono::system_clock::now();
    std::vector<bool> prime(limit, true);
    //for (long i = 0; i < m_Limit; i++)
    //    prime.push_back(true);
    
    std::fstream file;
    file.open("/Users/nathan/Downloads/Primes.txt", std::fstream::out);
    
    file << "2\n 3\n";
    
    
    for (long i = 2 * 2; i < limit + 1; i += 2)
        prime[i] = false;
    
    for (long i = 2 * 3; i < limit + 1; i += 3)
        prime[i] = false;
    
    uint64_t p = 5;
    
    while (p * p <= limit)
    {
        if (prime[p])
        {
            file << p << "\n";
            for (long i = 2 * p; i < limit + 1; i += p)
                prime[i] = false;
        }
        
        p += 2;
        
        if (prime[p])
        {
            file << p << "\n";
            for (long i = 2 * p; i < limit + 1; i += p)
                prime[i] = false;
        }
        
        p += 4;
    }
    
    //std::cout << "2" << std::endl;
    //for (int j = 3; j < m_Limit + 1; j += 2)
    //{
    //    if (prime[j])
    //        std::cout << j << std::endl;
    //}
    
    //std::chrono::time_point<std::chrono::system_clock> firstPart = std::chrono::system_clock::now();
    
    //auto elapsedSeconds = firstPart - start;
     
    //std::cout << "Elapsed time for first part: " << (elapsedSeconds.count())/1000000.0f << "s\n";
    
//    for (int j = 5; j < limit + 1; j += 4)
//    {
//        if (prime[j])
//            file << j << "\n";
//        
//        j += 2;
//        
//        if (prime[j])
//            file << j << "\n";
//    }
    file.close();
}

int main(void)
{
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;

    start = std::chrono::system_clock::now();
    prime_finder(1000000000);
    end = std::chrono::system_clock::now();
    
    auto elapsed_seconds = end - start;
     
    std::cout << "Total elapsed time: " << (elapsed_seconds.count())/1000000.0f << "s\n";
    return 0;
}
