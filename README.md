# C++ Logger
Thread safe Logger.
Based on drdoobs tutorial at http://www.drdobbs.com/cpp/a-lightweight-logger-for-c/240147505

* UML Diagram  
![alt text](wiki/Logger.jpg)

* std::stringstream  
..*C_Stream class uses std::stringstream to collect different types of imput and append it   
to the stringstream object.
*  template<typename... Args>
..*C_Stream class uses Template parameter pack to collect all the input and append it to
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
