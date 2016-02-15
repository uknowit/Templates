#include<iostream>
#include<vector>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/StdOutFormatTarget.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <time.h>
#include <string>
#include <sstream>
void Serialiser_XML_writer(xercesc::DOMDocument* pDOMDocument, const char* FullFilePath );

using namespace std;
//below macro gives all the required namespaces for Xerces
XERCES_CPP_NAMESPACE_USE


int main()
{

    XMLPlatformUtils::Initialize();

    // Pointer to our DOMImplementation.
    DOMImplementation *pDOMImplementation = NULL;

    // Get the DOM Implementation (used for creating DOMDocuments).
    // Also see: http://www.w3.org/TR/2000/REC-DOM-Level-2-Core-20001113/core.html
    pDOMImplementation = 
        DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("core"));

    DOMDocument * pDOMDocument = NULL;

    pDOMDocument = pDOMImplementation->createDocument(0, XMLString::transcode("ShipOrder"), 0);

     
    DOMElement * pRootElement = NULL;
    pRootElement = pDOMDocument->getDocumentElement();
    
    pRootElement->setAttributeNS(XMLString::transcode("http://www.w3.org/2001/XMLSchema-instance"),
                XMLString::transcode("xsi:noNamespaceSchemaLocation"), XMLString::transcode("my.xsd"));

    // Create a Comment node, and then append this to the root element.
    DOMComment * pDOMComment = NULL;
    pDOMComment = pDOMDocument->createComment(XMLString::transcode("Dates are formatted mm/dd/yy." 
            " Don't forget XML is case-sensitive."));
    pRootElement->appendChild(pDOMComment);


    // Create an Element node, then fill in some attributes,
    // and then append this to the root element.
    DOMElement * pDataElement = NULL;
    pDataElement = pDOMDocument->createElement(XMLString::transcode("data"));

    // Copy the current system date to a buffer, then set/create the attribute.
    pDataElement->setAttribute(XMLString::transcode("date"), XMLString::transcode(""));

    // Convert an integer to a string, then set/create the attribute.
    pDataElement->setAttribute(XMLString::transcode("integer"), XMLString::transcode("10"));

    // Convert a floating-point number to a wstring,
    // then set/create the attribute.
    std::wstringstream    myStream;
    myStream.precision(8);
    myStream.setf(std::ios_base::fixed, std::ios_base::floatfield);
    myStream << 3.1415926535897932384626433832795;
    const std::wstring ws(myStream.str());
    pDataElement->setAttribute(XMLString::transcode("float"), XMLString::transcode("3.1415926535897932384626433832795"));

    // Append 'pDataElement' to 'pRootElement'.
    pRootElement->appendChild(pDataElement);


    // Create an Element node, then fill in some attributes, add some text,
    // then append this to the 'pDataElement' element.
    DOMElement * pRow = NULL;
    pRow = pDOMDocument->createElement(XMLString::transcode("tow"));

    // Create some sample data.
    pRow->setAttribute(XMLString::transcode("index"), XMLString::transcode("10"));

    /*
       Create a text node and append this as well. Some people 
       prefer to place their data in the text node
       which is perfectly valid, others prefer to use 
       the attributes. A combination of the two is quite common.
       */
    DOMText* pTextNode = NULL;
    pTextNode = pDOMDocument->createTextNode(XMLString::transcode("Comments and" 
            " data can also go in text nodes."));
    pRow->appendChild(pTextNode);
    pDataElement->appendChild(pRow);


    // Create a new  row (this time putting data and descriptions into different places).
    pRow = pDOMDocument->createElement(XMLString::transcode("ConstantPI"));
    pRow->setAttribute(XMLString::transcode("description"), XMLString::transcode("The value of PI"));
    pTextNode = pDOMDocument->createTextNode(XMLString::transcode("3.1415"));
    pRow->appendChild(pTextNode);
    pDataElement->appendChild(pRow);


    // Create a new row.
    pRow = pDOMDocument->createElement(XMLString::transcode("UsefulLinks"));
    pRow->setAttribute(XMLString::transcode("website"), XMLString::transcode("http://www.programminggeeksinchrysalis.blogspot.com/"));
    pTextNode = pDOMDocument->createTextNode(XMLString::transcode("Blog worth Reading."));
    pRow->appendChild(pTextNode);
    pDataElement->appendChild(pRow);
    const char* path="sample.xml";
    Serialiser_XML_writer(pDOMDocument,path);

    //Release The Document after the xml file has been written
    pDOMDocument->release();
    XMLPlatformUtils::Terminate();
}
