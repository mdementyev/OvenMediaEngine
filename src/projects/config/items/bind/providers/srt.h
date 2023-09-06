//==============================================================================
//
//  OvenMediaEngine
//
//  Created by Getroot
//  Copyright (c) 2023 AirenSoft. All rights reserved.
//
//==============================================================================
#pragma once

#include "../../common/ranged_port.h"
#include "../../common/options.h"
#include "../../common/stream_map.h"
#include "./provider.h"

namespace cfg
{
	namespace bind
	{
		namespace pvd
		{
			struct SRT : public Provider<cmn::RangedPort>
			{
			protected:
				cmn::Options _options;
                cmn::StreamMap _stream_map;

			public:
				using Item::IsParsed;

				explicit SRT(const char *port)
					: Provider<cmn::RangedPort>(port)
				{
				}

				SRT()
				{
				}

				SRT(const char *port, const char *tls_port)
					: Provider<cmn::RangedPort>(port, tls_port)
				{
				}

				CFG_DECLARE_CONST_REF_GETTER_OF(GetOptions, _options);
				CFG_DECLARE_CONST_REF_GETTER_OF(GetStreamMap, _stream_map);

			protected:
				void MakeList() override
				{
					Provider<cmn::RangedPort>::MakeList();

					Item::Register<Optional>("Options", &_options);
					Item::Register<Optional>("StreamMap", &_stream_map);
				};
			};
		}  // namespace pvd
	}	   // namespace bind
}  // namespace cfg
