/*
	Copyright (c) 2011, pGina Team
	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
		* Redistributions of source code must retain the above copyright
		  notice, this list of conditions and the following disclaimer.
		* Redistributions in binary form must reproduce the above copyright
		  notice, this list of conditions and the following disclaimer in the
		  documentation and/or other materials provided with the distribution.
		* Neither the name of the pGina Team nor the names of its contributors 
		  may be used to endorse or promote products derived from this software without 
		  specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
	ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
	DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once

#include <Windows.h>
#include <string>

namespace pGina
{
	namespace Messaging
	{
		typedef enum PropertyType
		{
			Byte            = 0x00,
            Integer         = 0x01,
            Boolean         = 0x02,
            String          = 0x03,
            EmptyString     = 0x04,
		};

		class PropertyBase
		{
		public:
			std::wstring const& Name() { return m_name; }
			void                Name(std::wstring const& v) { m_name = v; }

			PropertyType        Type() { return m_type; }
			void				Type(PropertyType t) { m_type = t; }
			
		protected:
			std::wstring m_name;					
			PropertyType m_type;

			PropertyBase() {}	// Common folk shouldn't be creating me..		
			virtual void DummyVirtualForDynamicCastRequirement() {}
		};

		template <typename ValueType>
		class Property : public PropertyBase
		{
		public:
			Property(std::wstring const& name, ValueType const& value, PropertyType type) :
				m_value(value)
				{
					m_name = name;				
					m_type = type;
				}
			  			
			ValueType const&    Value() { return m_value; }
			void			    Value(ValueType const& v) { m_value = v; }

		private:			
			ValueType m_value;
		};
	}
}