#include "core.hpp"

namespace RestService {

using namespace rapidjson;

Core::Core()
{
    //ToDo...
}

Core::~Core()
{
    //ToDo...
}


void Core::setContentType(Headers c){

    switch (c) {
    case Headers::X_Urlencoded:
        headerType = ContentTypeHeader::APPLICATION_X_WWW_FROM_URLENCODED;
        break;
    case Headers::JSon:
        headerType = ContentTypeHeader::APPLICATION_JSON;
        break;
    case Headers::XHtml:
        headerType = ContentTypeHeader::APPLICATION_XHTML;
        break;
    case Headers::Xml:
        headerType = ContentTypeHeader::APPLICATION_XML;
        break;
    case Headers::Html:
        headerType = ContentTypeHeader::TEXT_HTML;
        break;
    case Headers::MultiPart:
        headerType = ContentTypeHeader::MULTIPART_FROM_DATA;
        break;
    }

}


std::string Core::whitespace_reduce(std::string_view str)
{
#if defined (_WIN64) || defined (__amd64__)
    uint64_t index;
#else
    uint32_t index;
#endif
    std::string var = str.data();
    while ((index = var.find("  ")) != std::string::npos)
        var.erase(index, 1);
    return var;
}

std::string Core::whitespace_leading(std::string_view str)
{
    std::string var = str.data();
    while (isspace(*var.begin()))
        var.erase(var.begin());
    return var;
}

std::string Core::escapeJSON(std::string_view input)
{
    std::string output;
    output.reserve(input.length());

    for (std::string::size_type i = 0; i < input.length(); ++i)
    {
        switch (input[i]) {
        case '"':
            output += "\\\"";
            break;
        case '/':
            output += "\\/";
            break;
        case '\b':
            output += "\\b";
            break;
        case '\f':
            output += "\\f";
            break;
        case '\n':
            output += "\\n";
            break;
        case '\r':
            output += "\\r";
            break;
        case '\t':
            output += "\\t";
            break;
        case '\\':
            output += "\\\\";
            break;
        default:
            output += input[i];
            break;
        }

    }

    return whitespace_reduce(output);
}

std::string Core::unescapeJSON(std::string_view input)
{
    State s = UNESCAPED;
    std::string output;
    output.reserve(input.length());

    for (std::string::size_type i = 0; i < input.length(); ++i)
    {
        switch(s)
        {
        case ESCAPED:
        {
            switch(input[i])
            {
            case '"':
                output += '\"';
                break;
            case '/':
                output += '/';
                break;
            case 'b':
                output += '\b';
                break;
            case 'f':
                output += '\f';
                break;
            case 'n':
                output += '\n';
                break;
            case 'r':
                output += '\r';
                break;
            case 't':
                output += '\t';
                break;
            case '\\':
                output += '\\';
                break;
            default:
                output += input[i];
                break;
            }

            s = UNESCAPED;
            break;
        }
        case UNESCAPED:
        {
            switch(input[i])
            {
            case '\\':
                s = ESCAPED;
                break;
            default:
                output += input[i];
                break;
            }
        }
        }
    }
    return output;
}


ApiException::ApiException()
{

}

ApiException::~ApiException()
{

}

void ApiException::setMessage(std::string_view message)
{
    m_message = message;
}

void ApiException::setCode(const int code)
{
    m_code = code;
}

std::string ApiException::getMessage()
{
    std::string temp;

    auto document = Document();

    std::cout << unescapeJSON(m_message) << std::endl;

    document.Parse(unescapeJSON(m_message).c_str());

    temp = document["return"]["message"].GetString();

    return temp;
}

int ApiException::getCode()
{
    int statusCode;

    auto document = Document();

    std::cout << unescapeJSON(m_message) << std::endl;

    document.Parse(unescapeJSON(m_message).c_str());

    statusCode = document["return"]["status"].GetInt();

    switch (statusCode) {
    case ReturnCode::Ret200:
        statusCode = 200;
        break;
    case ReturnCode::Ret400:
        statusCode = 400;
        break;
    case ReturnCode::Ret401:
        statusCode = 401;
        break;
    case ReturnCode::Ret402:
        statusCode = 402;
        break;
    case ReturnCode::Ret403:
        statusCode = 403;
        break;
    case ReturnCode::Ret404:
        statusCode = 404;
        break;
    case ReturnCode::Ret405:
        statusCode = 405;
        break;
    case ReturnCode::Ret406:
        statusCode = 406;
        break;
    case ReturnCode::Ret407:
        statusCode = 407;
        break;
    case ReturnCode::Ret409:
        statusCode = 409;
        break;
    case ReturnCode::Ret411:
        statusCode = 411;
        break;
    case ReturnCode::Ret412:
        statusCode = 412;
        break;
    case ReturnCode::Ret413:
        statusCode = 414;
        break;
    case ReturnCode::Ret414:
        statusCode = 414;
        break;
    case ReturnCode::Ret415:
        statusCode = 415;
        break;
    case ReturnCode::Ret416:
        statusCode = 416;
        break;
    case ReturnCode::Ret417:
        statusCode = 417;
        break;
    case ReturnCode::Ret418:
        statusCode = 418;
        break;
    case ReturnCode::Ret419:
        statusCode = 419;
        break;
    case ReturnCode::Ret422:
        statusCode = 422;
        break;
    case ReturnCode::Ret424:
        statusCode = 424;
        break;
    case ReturnCode::Ret426:
        statusCode = 426;
        break;
    case ReturnCode::Ret428:
        statusCode = 428;
        break;
    case ReturnCode::Ret431:
        statusCode = 431;
        break;
    case ReturnCode::Ret432:
        statusCode = 432;
        break;
    default:
        break;
    }

    return statusCode;
}

}
