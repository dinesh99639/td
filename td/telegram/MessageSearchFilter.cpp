//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2020
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "td/telegram/MessageSearchFilter.h"

#include "td/utils/common.h"

namespace td {

tl_object_ptr<telegram_api::MessagesFilter> get_input_messages_filter(MessageSearchFilter filter) {
  switch (filter) {
    case MessageSearchFilter::Empty:
      return make_tl_object<telegram_api::inputMessagesFilterEmpty>();
    case MessageSearchFilter::Animation:
      return make_tl_object<telegram_api::inputMessagesFilterGif>();
    case MessageSearchFilter::Audio:
      return make_tl_object<telegram_api::inputMessagesFilterMusic>();
    case MessageSearchFilter::Document:
      return make_tl_object<telegram_api::inputMessagesFilterDocument>();
    case MessageSearchFilter::Photo:
      return make_tl_object<telegram_api::inputMessagesFilterPhotos>();
    case MessageSearchFilter::Video:
      return make_tl_object<telegram_api::inputMessagesFilterVideo>();
    case MessageSearchFilter::VoiceNote:
      return make_tl_object<telegram_api::inputMessagesFilterVoice>();
    case MessageSearchFilter::PhotoAndVideo:
      return make_tl_object<telegram_api::inputMessagesFilterPhotoVideo>();
    case MessageSearchFilter::Url:
      return make_tl_object<telegram_api::inputMessagesFilterUrl>();
    case MessageSearchFilter::ChatPhoto:
      return make_tl_object<telegram_api::inputMessagesFilterChatPhotos>();
    case MessageSearchFilter::Call:
      return make_tl_object<telegram_api::inputMessagesFilterPhoneCalls>(0, false /*ignored*/);
    case MessageSearchFilter::MissedCall:
      return make_tl_object<telegram_api::inputMessagesFilterPhoneCalls>(
          telegram_api::inputMessagesFilterPhoneCalls::MISSED_MASK, false /*ignored*/);
    case MessageSearchFilter::VideoNote:
      return make_tl_object<telegram_api::inputMessagesFilterRoundVideo>();
    case MessageSearchFilter::VoiceAndVideoNote:
      return make_tl_object<telegram_api::inputMessagesFilterRoundVoice>();
    case MessageSearchFilter::Mention:
      return make_tl_object<telegram_api::inputMessagesFilterMyMentions>();
    case MessageSearchFilter::UnreadMention:
    case MessageSearchFilter::FailedToSend:
    default:
      UNREACHABLE();
      return nullptr;
  }
}

MessageSearchFilter get_message_search_filter(
    const tl_object_ptr<td_api::SearchMessagesFilter> &filter) {
  if (filter == nullptr) {
    return MessageSearchFilter::Empty;
  }
  switch (filter->get_id()) {
    case td_api::searchMessagesFilterEmpty::ID:
      return MessageSearchFilter::Empty;
    case td_api::searchMessagesFilterAnimation::ID:
      return MessageSearchFilter::Animation;
    case td_api::searchMessagesFilterAudio::ID:
      return MessageSearchFilter::Audio;
    case td_api::searchMessagesFilterDocument::ID:
      return MessageSearchFilter::Document;
    case td_api::searchMessagesFilterPhoto::ID:
      return MessageSearchFilter::Photo;
    case td_api::searchMessagesFilterVideo::ID:
      return MessageSearchFilter::Video;
    case td_api::searchMessagesFilterVoiceNote::ID:
      return MessageSearchFilter::VoiceNote;
    case td_api::searchMessagesFilterPhotoAndVideo::ID:
      return MessageSearchFilter::PhotoAndVideo;
    case td_api::searchMessagesFilterUrl::ID:
      return MessageSearchFilter::Url;
    case td_api::searchMessagesFilterChatPhoto::ID:
      return MessageSearchFilter::ChatPhoto;
    case td_api::searchMessagesFilterCall::ID:
      return MessageSearchFilter::Call;
    case td_api::searchMessagesFilterMissedCall::ID:
      return MessageSearchFilter::MissedCall;
    case td_api::searchMessagesFilterVideoNote::ID:
      return MessageSearchFilter::VideoNote;
    case td_api::searchMessagesFilterVoiceAndVideoNote::ID:
      return MessageSearchFilter::VoiceAndVideoNote;
    case td_api::searchMessagesFilterMention::ID:
      return MessageSearchFilter::Mention;
    case td_api::searchMessagesFilterUnreadMention::ID:
      return MessageSearchFilter::UnreadMention;
    case td_api::searchMessagesFilterFailedToSend::ID:
      return MessageSearchFilter::FailedToSend;
    default:
      UNREACHABLE();
      return MessageSearchFilter::Empty;
  }
}

} // namespace td