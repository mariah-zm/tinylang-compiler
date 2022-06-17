#include "xmlvisitor.ih"

XmlVisitor::XmlVisitor(string fileName)
{
    size_t pos = fileName.find('.');

    if (pos != std::string::npos)
        d_fileName = fileName.substr(0, pos) + ".xml";
    else
        d_fileName = fileName + ".xml";
    
    d_file.open(d_fileName);
}