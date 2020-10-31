#ifndef CORE_HPP
#define CORE_HPP

#include "common.hpp"

#include <iostream>
#include <string>
#include <string_view>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

namespace RestService {

/*!
 * \brief The Core class
 */
class RESTSERVICE_EXPORT Core
{
public:
    Core();
    ~Core();

    template <typename T>
    /**
   * @brief isset function checks any data values.
   * @param t
   * @return bool
   */
    [[maybe_unused]] static auto isset(T t)
    {
        if (const auto it = t; it != T{})
            // on success
            return true;
        else
            // on false...
            return false;
    }

/*!
 \@brief The HttpRowHeader struct
 \@details HTTP headers allow the client and the server to pass additional information with the request or the response.
 \An HTTP header consists of its case-insensitive name followed by a colon ':', then by its value (without line breaks). Leading white space before the value is ignored.
*/

    struct HttpRowHeader {
    public:

        /*!
     * \brief The HTTP Authorization request header contains the credentials to authenticate a user agent with a server,
     *  usually after the server has responded with a 401 Unauthorized status and the WWW-Authenticate header.
     */
        inline static std::string_view Authorization = "Authorization";

        /*!
     * \brief USER_AGENT Contains a characteristic string that allows the network protocol peers to identify the application type, operating system,
     *  software vendor or software version of the requesting software user agent.
     */
        inline static std::string_view USER_AGENT =  "User-Agent";

        /*!
     * \brief The Keep-Alive general header allows the sender to hint about how the connection may be used to set a timeout and a maximum amount of requests.
     */
        inline static std::string_view KEEP_ALIVE = "Keep-Alive";
    };

    /*!
 * \brief The Http row types is here.
 */
    struct HttpRowTypes {

    public:

        /*!
     * \brief Basic is a common type for Authentication.
     */
        inline static std::string_view  Basic = "Basic";

    };

    /*!
 * \brief The Content-Type entity header is used to indicate the media type of the resource.
 */
    struct ContentTypeHeader {
    public:

        /*!
     * \brief The Media type of the body of the request (used with POST and PUT requests).
     * Default. All characters are encoded before sent (spaces are converted to "+" symbols, and special characters are converted to ASCII HEX values)
     */
        inline static std::string_view  APPLICATION_X_WWW_FROM_URLENCODED = "Content-Type: application/x-www-form-urlencoded";

        /*!
     * \brief The MIME type of this content
     * Spaces are converted to "+" symbols, but no special characters are encoded
     */
        inline static std::string_view  TEXT_HTML = "Content-Type: text/plain";

        /*!
     * \brief The XHtml type of this content
     */
        inline static std::string_view  APPLICATION_XHTML = "Content-Type: application/xhtml+xml";

        /*!
     * \brief The Xml type of this content
     */
        inline static std::string_view  APPLICATION_XML = "Content-Type: application/xml";

        /*!
     * \brief The JSon type of this content
     */
        inline static std::string_view  APPLICATION_JSON = "Content-Type: application/json";


        /*!
     * \brief No characters are encoded.
     * This value is required when you are using forms that have a file upload control.
     */
        inline static std::string_view  MULTIPART_FROM_DATA =  "Content-Type: multipart/form-data";
    };

    /*!
     * \brief The ContentTypes enum
     */
    enum class Headers {
        X_Urlencoded,
        JSon,
        Html,
        XHtml,
        Xml,
        MultiPart
    };

    /*!
     * \brief setContentType
     */
    [[maybe_unused]] void setContentType(Headers c);

    /*!
     * \brief The HTTP_METHOD enum
     * \param GET is used to request data from a specified resource.
     * \param POST is used to send data to a server to create/update a resource.
     * \param PUT is used to send data to a server to create/update a resource.
     * \param DELETE_EX method deletes the specified resource.
     * \param HEAD is almost identical to GET, but without the response body.
     * \param OPTIONS method describes the communication options for the target resource.
     * \param PATCH method is a request method supported by the HTTP protocol for making partial changes to an existing resource.
     */
    enum class HTTP_METHOD {
        GET,
        POST,
        PUT,
        DELETE_EX,
        HEAD,
        OPTIONS,
        PATCH
    };

    /*!
     * Message:	Successful Description:
     * 200 OK	The request is OK (this is the standard response for successful HTTP requests)
     * 201 Created	The request has been fulfilled, and a new resource is created
     * 202 Accepted	The request has been accepted for processing, but the processing has not been completed
     * 203 Non-Authoritative Information	The request has been successfully processed, but is returning information that may be from another source
     * 204 No Content	The request has been successfully processed, but is not returning any content
     * 205 Reset Content	The request has been successfully processed, but is not returning any content, and requires that the requester reset the document view
     * 206 Partial Content	The server is delivering only part of the resource due to a range header sent by the client
    */
    enum class HTTP_MESSAGE_SUCCESS {
        OK              = 200,
        Created         = 201,
        Accepted        = 202,
        Non_AI          = 203,
        No_Content      = 204,
        Reset_Content   = 205,
        Partial_Content = 206
    };

    /*!
     * Message:	Redirection Description:
     * 300 Multiple Choices	A link list. The user can select a link and go to that location. Maximum five addresses
     * 301 Moved Permanently	The requested page has moved to a new URL
     * 302 Found	The requested page has moved temporarily to a new URL
     * 303 See Other	The requested page can be found under a different URL
     * 304 Not Modified	Indicates the requested page has not been modified since last requested
     * 306 Switch Proxy	No longer used
     * 307 Temporary Redirect	The requested page has moved temporarily to a new URL
     * 308 Resume Incomplete	Used in the resumable requests proposal to resume aborted PUT or POST requests
    */
    enum class HTTP_MESSAGE_REDIRECTION {
        MultipleChoices     = 300,
        MovedPermanently    = 301,
        FoundNewUrl         = 302,
        See_Other           = 303,
        Not_Modified        = 304,
        Switch_Proxy        = 306,
        Temporary_Redirect  = 307,
        Resume_Incomplete   = 308
    };

    /*!
     * \brief The State enum
     */
    enum State { ESCAPED, UNESCAPED };

    /*!
     * \brief The Normal ReturnCode enum
     */
    enum ReturnCode {
        Ret200    = 200, // Number 200 is normal status [Success mode]
        Ret400    = 400,
        Ret401    = 401,
        Ret402    = 402,
        Ret403    = 403,
        Ret404    = 404,
        Ret405    = 405,
        Ret406    = 406,
        Ret407    = 407,
        Ret409    = 409,
        Ret411    = 411,
        Ret412    = 412,
        Ret413    = 413,
        Ret414    = 414,
        Ret415    = 415,
        Ret416    = 416,
        Ret417    = 417,
        Ret418    = 418,
        Ret419    = 419,
        Ret422    = 422,
        Ret424    = 424,
        Ret426    = 426,
        Ret428    = 428,
        Ret431    = 431,
        Ret432    = 432
    };

    /*!
     * \brief whitespace_reduce
     * \param str with reduce string
     * \return
     */
    [[maybe_unused]] std::string whitespace_reduce(std::string_view str);

    /*!
     * \brief whitespace_leading
     * \param str with leading string
     * \return
     */
    [[maybe_unused]] std::string whitespace_leading(std::string_view str);

    /*!
     * \brief escapeJSON
     * \param input for escaping from json template
     * \return
     */
    [[maybe_unused]] std::string escapeJSON(std::string_view input);

    /*!
     * \brief unescapeJSON
     * \param input for unscaping json template
     * \return
     */
    [[maybe_unused]] std::string unescapeJSON(std::string_view input);

public:
    inline static std::string_view headerType = {NULL_STR};

};

/*!
   * \brief The ApiException class
   */
class RESTSERVICE_EXPORT ApiException : private Core {
public:
    ApiException();
    ~ApiException();

    /*!
     * \brief getMessage function will return message from ARVAN Server.
     * \return string
     */
    [[maybe_unused]] std::string getMessage();

    /*!
     * \brief getCode function will return status code number from ARVAN Server.
     * \return
     */
    [[maybe_unused]] int getCode();

    /*!
     * \brief setMessage
     * \param message
     */
    [[maybe_unused]] void setMessage(std::string_view message);

    /*!
     * \brief setCode
     * \param code
     */
    [[maybe_unused]] void setCode(const int code);

private:
    inline static std::string_view m_message = {NULL_STR};
    inline static int m_code = {0};

};

}

#endif // API_HPP
