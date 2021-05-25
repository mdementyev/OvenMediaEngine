//==============================================================================
//
//  Transcode
//
//  Created by Kwon Keuk Han
//  Copyright (c) 2018 AirenSoft. All rights reserved.
//
//==============================================================================
#pragma once

#include "../../transcoder_decoder.h"

class DecoderAVC : public TranscodeDecoder
{
public:
	DecoderAVC(const info::Stream &stream_info)
		: TranscodeDecoder(stream_info)
	{
	}

	AVCodecID GetCodecID() const noexcept override
	{
		return AV_CODEC_ID_H264;
	}

	bool Configure(std::shared_ptr<TranscodeContext> context) override;

	void ThreadDecode() override;

	std::shared_ptr<MediaFrame> RecvBuffer(TranscodeResult *result) override;
};