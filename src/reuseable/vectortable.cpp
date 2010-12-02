#include <QDebug>
#include <QList>
#include "vectortable.h"

VectorTable::VectorTable( const QStringList& tags ) :
    width( tags.size() ), height( 0 ), tags( tags )
{
    foreach( QString str, tags )
        this->table[str] = new QVector<double>;
}

VectorTable::VectorTable( const VectorTable& table )
{
    if ( this == &table )
        return;

    this->width  = table.getWidth();
    this->height = table.getHeight();
    this->tags   = table.getTags();
    QList<QVector<double>*> tmp = this->table.values();
    this->table.clear();
    foreach( QString str, tags )
        this->table[str] = new QVector<double>( *table.getColumn( str ) );

    qDeleteAll( tmp );
}

VectorTable::~VectorTable()
{
    qDeleteAll( this->table.values() );
}

int VectorTable::getWidth() const
{
    return this->width;
}

int VectorTable::getHeight() const
{
    return this->height;
}

QVector<double> VectorTable::getRow( int i ) const
{
    if ( i < 0 || i > this->height )
        qFatal( "VectorTable: row does not exist" );

    QVector<double> vec;
    foreach( QString tag, this->tags )
        vec << this->table[tag]->at(i);

    return vec;
}

const QVector<double>* VectorTable::getColumn( const QString& str ) const
{
    if ( ! this->table.contains( str ) )
        qFatal( "VectorTable: table does not contain this column" );

    return this->table[str];
}

const QStringList& VectorTable::getTags() const
{
    return this->tags;
}

VectorTable VectorTable::mid( int pos, int length ) const
{
    if ( this->height < pos || this->height < pos + length )
        qFatal( "VectorTable: incorect mid" );

    VectorTable result( this->getTags() );
    for ( int i = pos; i < this->height; i++ )
    {
        if ( length == 0 )
            break;

        result << this->getRow( i );
        length--;
    }

    return result;
}

void VectorTable::addRow( const QStringList& row )
{
    if ( this->width != row.size() )
        qFatal( "VectorTable: incorect row" );

    foreach( QString str, this->tags )
        *this->table[str] << row.at( this->tags.indexOf( str ) ).toDouble();

    this->height++;
}

void VectorTable::addRow( const QVector<double>& row )
{
    if ( this->width != row.size() )
        qFatal( "VectorTable: incorect row" );

    foreach( QString str, this->tags )
        *this->table[str] << row.at( this->tags.indexOf( str ) );

    this->height++;
}

VectorTable& VectorTable::operator = ( const VectorTable& table )
{
    if ( this != &table )
    {
        this->width  = table.getWidth();
        this->height = table.getHeight();
        this->tags   = table.getTags();
        QList<QVector<double>*> tmp = this->table.values();
        this->table.clear();
        foreach( QString str, tags )
            this->table[str] = new QVector<double>( *table.getColumn( str ) );

        qDeleteAll( tmp );
    }

    return *this;
}

VectorTable& VectorTable::operator << ( const QStringList& row )
{
    this->addRow( row );

    return *this;
}

VectorTable& VectorTable::operator << ( const QVector<double>& row )
{
    this->addRow( row );

    return *this;
}
