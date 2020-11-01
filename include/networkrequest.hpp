#ifndef NETWORKREQUEST_HPP
#define NETWORKREQUEST_HPP

#include "common.hpp"
#include <memory>
#include <iostream>
#include <string>
#include <string_view>
#include <map>

#include <curl/curl.h>

/*!
* \brief Network Manager of Curl
*/

namespace RestService {

//using CurlEasy  = CURL;
//using CurlShare = CURLSH;

class NetworkRequest;
/*!
* \brief NetworkRequest class
*/
class RESTSERVICE_EXPORT NetworkRequest
{
public:

    NetworkRequest  ();  //! NetworkRequest default constructor.
    ~NetworkRequest ();  //! NetworkRequest destructor.

    /*!
     * \brief Authorazation function.
     * \param username
     * \param password
     */
    [[maybe_unused]] void setAuthorazation   (const std::string& username, const std::string& password);

    /*!
     * brief WriteCallback : https://curl.haxx.se/libcurl/c/CURLOPT_WRITEFUNCTION.html
     * \details This callback function gets called by libcurl as soon as there is data received that needs to be saved.
     * - For most transfers, this callback gets called many times and each invoke delivers another chunk of data.
     * - ptr points to the delivered data, and the size of that data is nmemb; size is always 1.
     * \param contents
     * \param size
     * \param nmemb
     * \param userp
     * \return
     */
    [[maybe_unused]] static size_t WriteCallback(char *data, size_t size, size_t nmemb, std::string *buffer);

    /*!
     * \brief get method for send request
     * \param url is api uri
     */
    [[maybe_unused]] void get(const std::string& url);

    /*!
     * \brief post method for send request
     * \param url is api uri
     * \param query is parameters
     */
    [[maybe_unused]] void post(const std::string& url, const std::string& query);

    /*!
     * \brief Returns result of network request.
     * \return result of data.
     */
    [[maybe_unused]] std::string getResult();

protected:

    /*!
     * \brief always cleanup method for End a libcurl easy handle
     */
    [[maybe_unused]] void clean();

    /*!
     * \brief global libcurl cleanup
     */
    [[maybe_unused]] void cleanGlobal();

    /*!
     * \brief Result function for set result.
     * \param res
     */
    void setResult          (const std::string& res);

    /*!
     * \brief Progress function for set percent of progress
     * \param val
     */
    void setProgress        (const int &val);

protected:
    CURL        *curl;
    CURLcode    res;
    std::string readBuffer          = {NULL_STR};
    std::string result              = {NULL_STR};
    struct curl_slist *ctype_list   = nullptr;

};

} //!WebService

#endif // NETWORKREQUEST_HPP
