// Generated with ImRAD 0.1
// github.com/tpecholt/imrad

#pragma once
#include <string>
#include <functional>
#include <imgui.h>
#include "imrad.h"

class ComboDlg
{
public:
    /// @interface
    void OpenPopup(std::function<void(ImRad::ModalResult)> clb = [](ImRad::ModalResult){});
    void ClosePopup();
    void Draw();

    std::string title = "Items";
    std::string value;
    ImFont* font = nullptr;

private:
    /// @impl

    bool requestOpen = false;
    bool requestClose = false;
    std::function<void(ImRad::ModalResult)> callback;

};

extern ComboDlg comboDlg;
