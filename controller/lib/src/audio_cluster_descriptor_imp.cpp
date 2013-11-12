/*
 * Licensed under the MIT License (MIT)
 *
 * Copyright (c) 2013 AudioScience Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * audio_cluster_descriptor_imp.cpp
 *
 * Audio Cluster descriptor implementation
 */

#include "enumeration.h"
#include "log_imp.h"
#include "end_station_imp.h"
#include "audio_cluster_descriptor_imp.h"

namespace avdecc_lib
{
	audio_cluster_descriptor_imp::audio_cluster_descriptor_imp(end_station_imp *end_station_obj, const uint8_t *frame, size_t pos, size_t frame_len) : descriptor_base_imp(end_station_obj)
	{
		audio_cluster_desc_read_returned = jdksavdecc_descriptor_audio_cluster_read(&audio_cluster_desc, frame, pos, frame_len);

		if(audio_cluster_desc_read_returned < 0)
		{
			log_imp_ref->post_log_msg(LOGGING_LEVEL_ERROR, "desc_config_read error");
			assert(audio_cluster_desc_read_returned >= 0);
		}

	}

	audio_cluster_descriptor_imp::~audio_cluster_descriptor_imp() {}

	uint16_t STDCALL audio_cluster_descriptor_imp::get_descriptor_type()
	{
		assert(audio_cluster_desc.descriptor_type == JDKSAVDECC_DESCRIPTOR_AUDIO_CLUSTER);
		return audio_cluster_desc.descriptor_type;
	}

	uint16_t STDCALL audio_cluster_descriptor_imp::get_descriptor_index()
	{
		assert(audio_cluster_desc.descriptor_index == 0);
		return audio_cluster_desc.descriptor_index;
	}

	uint8_t * STDCALL audio_cluster_descriptor_imp::get_object_name()
	{
		return audio_cluster_desc.object_name.value;
	}

	uint16_t STDCALL audio_cluster_descriptor_imp::get_localized_description()
	{
		return audio_cluster_desc.localized_description;
	}

	uint16_t STDCALL audio_cluster_descriptor_imp::get_signal_type()
	{
		return audio_cluster_desc.signal_type;
	}

	uint16_t STDCALL audio_cluster_descriptor_imp::get_signal_index()
	{
		return audio_cluster_desc.signal_index;
	}

	uint16_t STDCALL audio_cluster_descriptor_imp::get_signal_output()
	{
		return audio_cluster_desc.signal_output;
	}

	uint32_t STDCALL audio_cluster_descriptor_imp::get_path_latency()
	{
		return audio_cluster_desc.path_latency;
	}

	uint32_t STDCALL audio_cluster_descriptor_imp::get_block_latency()
	{
		return audio_cluster_desc.block_latency;
	}

	uint16_t STDCALL audio_cluster_descriptor_imp::get_channel_count()
	{
		return audio_cluster_desc.channel_count;
	}

	uint8_t STDCALL audio_cluster_descriptor_imp::get_format()
	{
		return audio_cluster_desc.format;
	}
}