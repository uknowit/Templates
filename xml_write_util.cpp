#include <iostream>
#include <vector>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/StdOutFormatTarget.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <time.h>
#include <string>
#include <sstream>
using namespace std;
//below macro gives all the required namespaces for Xerces
XERCES_CPP_NAMESPACE_USE

void Serialiser_XML_writer(xercesc::DOMDocument* pDOMDocument, const char* FullFilePath )
{
    DOMImplementation *pImplement = NULL;
    DOMLSSerializer *pSerializer = NULL; // @DOMWriter
    LocalFileFormatTarget *pTarget = NULL; 

    //Return the first registered implementation that has the desired features. In this case, we are after
    //a DOM implementation that has the LS feature... or Load/Save.

    pImplement = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("core"));

    //From the DOMImplementation, create a DOMWriter.
    //DOMWriters are used to serialize a DOM tree [back] into an XML document.

    pSerializer = ((DOMImplementationLS*)pImplement)->createLSSerializer(); 
    DOMLSOutput *pOutput = ((DOMImplementationLS*)pImplement)->createLSOutput();
    DOMConfiguration *pConfiguration = pSerializer->getDomConfig();

    // Have a nice output
    if (pConfiguration->canSetParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true))
        pConfiguration->setParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true); 
    pTarget = new LocalFileFormatTarget(FullFilePath);
    pOutput->setByteStream(pTarget);

    //pSerializer->write(pDOMDocument->getDocumentElement(), pOutput); // missing header "" if used
    pSerializer->write(pDOMDocument, pOutput); 

    delete pTarget;
    pOutput->release();
    pSerializer->release();
}

