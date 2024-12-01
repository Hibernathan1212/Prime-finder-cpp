#include <iostream>

#include <fstream>
#include <vector>

void prime_finder(const uint64_t limit)
{
    std::chrono::time_point<std::chrono::system_clock> start;
    start = std::chrono::system_clock::now();
    std::vector<bool> prime(limit / 2, true);
    //for (long i = 0; i < m_Limit; i++)
    //    prime.push_back(true);
    
    std::fstream file;
    file.open("/Users/nathan/Downloads/Primes.txt", std::fstream::out);
    
    ////////////////////////////////////////////////////////////
    
//    file << "2\n3\n";
//    
//    uint64_t p = 5;
//    
//    while (p <= limit)
//    {
//        if (prime[p])
//        {
//            file << p << "\n";
//            for (long i = 2 * p; i < limit + 1; i += p)
//                prime[i] = false;
//        }
//        
//        p += 2;
//        
//        if (prime[p])
//        {
//            file << p << "\n";
//            for (long i = 2 * p; i < limit + 1; i += p)
//                prime[i] = false;
//        }
//        
//        p += 4;
//    }
    
    ///////////////////////////////////////////////////////////////////////////////////
    
//    file << "2\n3\n";
//    
//    
//    //for (long i = 3; i < limit/2 + 1; i += (2 * 3 + 1))
//    //    prime[i] = false;
//
//    uint64_t p = 2;
//
//    //0, 1, 2, 3, 4, 5, 6, 7
//    //1, 3, 5, 7, 9, 11, 13, 15
//    
//    while (p < limit/2)
//    {
//        if (prime[p])
//        {
//            file << p * 2 + 1 << "\n";
//            for (long i = p; i < limit/2 + 1; i += (2 * p + 1))
//                prime[i] = false;
//        }
//        
//        p += 1;
//        
//        if (prime[p])
//        {
//            file << p * 2 + 1 << "\n";
//            for (long i = p; i < limit/2 + 1; i += (2 * p + 1))
//                prime[i] = false;
//        }
//        
//        p += 2;
//    }
    
    ////////////////////////////////////////////////////////////////
    
    file << "2\n3\n";
        
    uint64_t p = 0;
    
    //0, 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13
    //5, 7, 11, 13, 17, 19, 23, 25, 29, 31, 35, 37, 41, 43
    
    while (p < limit/3)
    {
        if (prime[p])
        {
            uint64_t val = (p + 1) * 3 - (p % 2 - 2);
            file << val << "\n";
            
            for (long i = val; i < limit; i += val)
            {
                if (i % 6 == 5)
                {
                    prime[((i + 1)/6 - 1) * 2] = false;
                }
                
                if (i % 6 == 1)
                {
                    prime[((i + 1)/6 - 1) * 2 + 1] = false;
                }
            }
        }
        p++;
    }
    
    /////////////////////////////////////////////////////

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
    
    ////////////////////////////////////////////////
    file.close();
}

int main(void)
{
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;

    start = std::chrono::system_clock::now();
    prime_finder(100000000);
    end = std::chrono::system_clock::now();
    
    auto elapsed_seconds = end - start;
     
    std::cout << "Total elapsed time: " << (elapsed_seconds.count())/1000000.0f << "s\n";

    return 0;
}
