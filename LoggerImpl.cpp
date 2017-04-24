/**
 * Implementation for Logger namespace
 */

#include "LoggerImpl.h"

class C_Stream;
template class  Logger::C_Logger<Logger::C_Stream>;

/**
 * Desctructor
 */
Logger::I_Stream::~I_Stream() {

}

/**
 * Constructor
 */
Logger::C_Stream::C_Stream() {
    m_stream = std::make_unique<std::ofstream>();
}

/**
 * Destructor
 */
Logger::C_Stream::~C_Stream() {
    if(m_stream)
    {
        close();
    }
}

/**
 * Opens a Stream
 *
 * @param name - the name of the stream to write to
 */
void Logger::C_Stream::open(const std::string& streamName) {
    m_stream->open( streamName.c_str(), std::ofstream::out | std::ofstream::app);
    if(!m_stream->is_open())
    {
        throw(std::runtime_error("LOGGER: Unable to open an output m_stream"));
    }
}

/**
 * Closes the stream
 */
void Logger::C_Stream::close() {
    if(m_stream)
    {
        m_stream->close();
    }
}

/**
 * Writes to a stream
 * @param msg - message to be written to the stream
 */
void Logger::C_Stream::write(const std::string& msg) {
    (*m_stream) << msg << std::endl;
}

/**
 * Sets the time.
 * Appends the m_streamString
 * @tparam Stream
 */
template< typename Stream >
void Logger::C_Logger<Stream>::setTime() {
    std::string time_str;
    time_t raw_time;
    time(& raw_time);
    time_str = ctime(&raw_time);

    m_streamString << time_str.substr(0, time_str.size() - 1) << " : " ;
}

/**
 * Base case for print(args...)
 * When there are no more arguments,
 * this method is called to write
 * the m_streamString to the stream
 *
 * @tparam Stream
 */
template<typename Stream>
void Logger::C_Logger<Stream>::print() {
    stream->write( m_streamString.str() );
    m_streamString.str("");
}

/**
 * Constructor
 * Accepts Parameter Type
 *
 * @tparam Stream type
 * @param name -
 */
template<typename Stream>
Logger::C_Logger<Stream>::C_Logger(const std::string& streamName) {

    stream = new Stream;
    if( !stream )
    {
        throw std::runtime_error("LOGGER: Unable to create the logger instance");
    }
    stream->open(streamName);
}

/**
 * Destructor
 * @tparam Stream
 */
template<typename Stream>
Logger::C_Logger<Stream>::~C_Logger(){

}

/**
 * Sets
 *
 * @tparam Stream
 * @param type
 */
template< typename Stream>
void Logger::C_Logger<Stream>::setLogStream(Logger::Type type) {
    switch( type )
    {
        case Type::Debug:
            m_streamString << "<DEBUG> ";
            break;
        case Type::Warning:
            m_streamString << "<WARNING> ";
            break;
        case Type::Error:
            m_streamString << "<ERROR> ";
            break;
    };
}
