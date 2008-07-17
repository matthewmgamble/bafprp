/*
Copyright (C) 2008 by Charles Solar
charlessolar@gmail.com

This file is part of bafprp.

bafprp is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

bafprp is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with bafprp.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "servicetraffic.h"
#include "output.h"

namespace bafprp
{
	const ServiceTrafficFieldMaker ServiceTrafficFieldMaker::registerThis;

	IField* ServiceTrafficFieldMaker::make() const
	{
		LOG_TRACE( "ServiceTrafficFieldMaker::make" );
		LOG_TRACE( "/ServiceTrafficFieldMaker::make" );
		return new ServiceTraffic;
		
	}

	ServiceTraffic::ServiceTraffic() : IField()
	{
		LOG_TRACE( "ServiceTraffic::ServiceTrafficFieldConverter" );
		LOG_TRACE( "/ServiceTraffic::ServiceTrafficFieldConverter" );
	}


	ServiceTraffic::~ServiceTraffic()
	{
		LOG_TRACE( "ServiceTraffic::~ServiceTrafficFieldConverter" );
		LOG_TRACE( "/ServiceTraffic::~ServiceTrafficFieldConverter" );
	}

	bool ServiceTraffic::convert ( const BYTE* data )
	{
		LOG_TRACE( "ServiceTraffic::convert" );
		_return = getChars( data, getSize() );
		_converted = true;

		if( _return.length() != getSize() ) 
		{
			_lastError = "Data read is not the correct size";
			_converted = false;
		}

		LOG_TRACE( "/ServiceTraffic::convert" );
		return _converted;
	}

	int ServiceTraffic::getInt()
	{
		LOG_TRACE( "ServiceTraffic::getInt" );

		int ret;
		if( !_converted )
		{
			_lastError = "Tried to get int before field was converted";
			ret = 0;
		}
		else
			ret = atoi( _return.c_str() );

		LOG_TRACE( "/ServiceTraffic::getInt" );
		return ret;
	}

	long ServiceTraffic::getLong()
	{
		LOG_TRACE( "ServiceTraffic::getLong" );

		long ret;
		if( !_converted )
		{
			_lastError = "Tried to get long before field was converted";
			ret = 0;
		}
		else
			ret = atol( _return.c_str() );

		LOG_TRACE( "/ServiceTraffic::getLong" );
		return ret;
	}

	std::string ServiceTraffic::getString()
	{
		LOG_TRACE( "ServiceTraffic::getString" );

		std::string ret;
		if( !_converted )
		{
			_lastError = "Tried to get string before field was converted";
			ret = "";
		}
		else
			ret = _return;

		LOG_TRACE( "/ServiceTraffic::getString" );
		return ret;
	}
}
