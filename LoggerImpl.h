/**
 *
 */

#ifndef LOGGER_LOGGER_H
#define LOGGER_LOGGER_H

#include <fstream>
#include <memory>
#include <mutex>
#include <sstream>
#include <iostream>
#include <vector>

namespace Logger {

    enum Type {
        Debug,
        Error,
        Warning
    };

    class I_Stream {
    public:
        virtual void open(const std::string &name) = 0;

        virtual void close() = 0;

        virtual void write(const std::string &msg) = 0;

        virtual ~I_Stream();
    };

    class C_Stream : public I_Stream {
    private:
        std::unique_ptr<std::ofstream> m_stream;

    public:
        C_Stream();

        ~C_Stream() override;

        void open(const std::string &) override;

        void close() override;

        void write(const std::string &) override;
    };

    template<typename Stream>
    class C_Logger {

    private: // member variables

        std::stringstream m_streamString;
        I_Stream *stream;
        std::mutex m_mutex;

    private: // member functions

        void setTime();

        void print();

        void setLogStream(Logger::Type);

        /**
         * Tail recursive method
         * With every recursive call, the first parameter (head)
         * appends m_streamString, and the second (tail) is used
         * as a parameter to the next recursive call until
         * the are no parameters. At the end when there are
         * no parameters, the base case function print() is
         * called to write the m_streamString to the stream
         *
         *
         * @tparam Head
         * @tparam Tail
         * @param head - head of the list
         * @param tail - the rest of the list
         */
        template<typename Head, typename... Tail>
        void print(Head head, Tail... tail) {
            m_streamString << head;
            print(tail...);
        }

    public: // member functions

        C_Logger(const std::string &name);

        ~C_Logger();

        template<Logger::Type type, typename... Args>
        void write(Args... args) {
            m_mutex.lock();
            setLogStream(type);
            setTime();

            print(args...);

            m_mutex.unlock();
        }
    };
};



#endif //LOGGER_LOGGER_H
