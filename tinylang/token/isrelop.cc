#include "token.ih"

bool Token::isRelOp() const
{
    try 
    {
        d_relOpMap.at(d_value);
        return true;
    }
    catch (out_of_range &ex) 
    {
        return false;
    }
}