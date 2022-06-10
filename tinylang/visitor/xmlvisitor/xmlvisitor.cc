#include "xmlvisitor.ih"

XmlVisitor::XmlVisitor(string fileName)
{
    string newName;
    size_t pos = fileName.find('.');

    if (pos != std::string::npos)
        newName = fileName.substr(0, pos) + ".xml";
    else
        newName = fileName + ".xml";
    
    d_file.open(newName);
}