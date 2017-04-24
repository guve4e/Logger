# C++ Logger
Thread safe Logger.
Based on drdoobs tutorial at http://www.drdobbs.com/cpp/a-lightweight-logger-for-c/240147505

* UML Diagram  
![alt text](wiki/Logger.jpg)

* std::stringstream [Read about std::stringstream](http://www.cplusplus.com/reference/sstream/stringstream/stringstream/)  
..*C_Stream class uses std::stringstream to collect different types of imput and append it   
to the stringstream object.
*  template<typename... Args>  [Read about Template Parameter Pack Here]( http://en.cppreference.com/w/cpp/language/parameter_pack)  
..*C_Stream class uses Template parameter pack to collect all the input and append it  
to the stringstream object. Two member functions print() are defined:
```
        template<typename Head, typename... Tail>
        void print(Head head, Tail... tail) {
            m_streamString << head;
            print(tail...);
        }
```
and  
```
      template<typename Stream>
      void Logger::C_Logger<Stream>::print() {
          stream->write( m_streamString.str() );
          m_streamString.str("");
      }
```
Member function void print(Head head, Tail... tail) is Tail recursive method. With every  
recursive call, the first parameter (head) appends m_streamString(std::streamstring),  
and the second (tail) is used as a parameter to the next recursive call until the are no  
parameters. At the end when there are no parameters, the base case function print() is   
called to write the m_streamString(std::streamstring) to the stream 
