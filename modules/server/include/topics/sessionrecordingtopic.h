/*****************************************************************************************
 *                                                                                       *
 * OpenSpace                                                                             *
 *                                                                                       *
 * Copyright (c) 2014-2019                                                               *
 *                                                                                       *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this  *
 * software and associated documentation files (the "Software"), to deal in the Software *
 * without restriction, including without limitation the rights to use, copy, modify,    *
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and to    *
 * permit persons to whom the Software is furnished to do so, subject to the following   *
 * conditions:                                                                           *
 *                                                                                       *
 * The above copyright notice and this permission notice shall be included in all copies *
 * or substantial portions of the Software.                                              *
 *                                                                                       *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,   *
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A         *
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT    *
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF  *
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE  *
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                         *
 ****************************************************************************************/

#ifndef __OPENSPACE_MODULE_SERVER___SESSION_RECORDING_TOPIC___H__
#define __OPENSPACE_MODULE_SERVER___SESSION_RECORDING_TOPIC___H__

#include <modules/server/include/topics/topic.h>
#include <openspace/interaction/sessionrecording.h>

namespace openspace {

class SessionRecordingTopic : public Topic {
public:
    SessionRecordingTopic();
    virtual ~SessionRecordingTopic();

    void handleJson(const nlohmann::json& json) override;
    bool isDone() const override;

private:
    const int UnsetOnChangeHandle = -1;

    //Provides the idle/recording/playback state int value in json message
    nlohmann::json state();

    int _stateCallbackHandle = UnsetOnChangeHandle;
    bool _isDone = false;
    std::chrono::system_clock::time_point _lastUpdateTime;
    interaction::SessionRecording::SessionState _lastState;
};

} // namespace openspace

#endif // __OPENSPACE_MODULE_SERVER___SESSION_RECORDING_TOPIC___H__