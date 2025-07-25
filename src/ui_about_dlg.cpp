// Generated with ImRAD 0.1
// github.com/xyz

#include "ui_about_dlg.h"
#include "utils.h"

AboutDlg aboutDlg;

void AboutDlg::OpenPopup(std::function<void(ImRad::ModalResult)> clb)
{
    callback = clb;
    modalResult = ImRad::None;
    auto *ioUserData = (ImRad::IOUserData *)ImGui::GetIO().UserData;
    ioUserData->dimBgRatio = 1.f;
    ImGui::OpenPopup(ID);
    Init();
}

void AboutDlg::ClosePopup(ImRad::ModalResult mr)
{
    modalResult = mr;
    auto *ioUserData = (ImRad::IOUserData *)ImGui::GetIO().UserData;
    ioUserData->dimBgRatio = 0.f;
}


void AboutDlg::Init()
{
    // TODO: Add your code here
}

void AboutDlg::Draw()
{
    /// @style imrad
    /// @unit px
    /// @begin TopWindow
    auto* ioUserData = (ImRad::IOUserData*)ImGui::GetIO().UserData;
    ID = ImGui::GetID("###AboutDlg");
    ImGui::PushStyleColor(ImGuiCol_PopupBg, ImGui::GetStyleColorVec4(ImGuiCol_TitleBgActive));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 60, 15 });
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, { 10, 7 });
    ImGui::SetNextWindowPos(ioUserData->WorkRect().GetCenter(), 0, { 0.5f, 0.5f }); //Center
    ImGui::SetNextWindowSize({ 0, 0 }); //{ 0, 0 }
    bool tmpOpen = true;
    if (ImGui::BeginPopupModal("About###AboutDlg", &tmpOpen, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize))
    {
        if (ioUserData->activeActivity != "")
            ImRad::RenderDimmedBackground(ioUserData->WorkRect(), ioUserData->dimBgRatio);
        if (modalResult != ImRad::None)
        {
            ImGui::CloseCurrentPopup();
            if (modalResult != ImRad::Cancel)
                callback(modalResult);
        }
        /// @separator

        // TODO: Add Draw calls of dependent popup windows here

        /// @begin Image
        if (!value1)
            value1 = ImRad::LoadTextureFromFile("style/icon-40.png");
        ImGui::Image(value1.id, { (float)value1.w, (float)value1.h });
        /// @end Image

        // TODO: Add Draw calls of dependent popup windows here

        /// @begin Text
        ImGui::SameLine(0, 2 * ImGui::GetStyle().ItemSpacing.x);
        ImGui::PushFont(nullptr, ImGui::GetStyle().FontSizeBase * 1.5f);
        ImGui::TextUnformatted(ImRad::Format("{}", VER_STR).c_str());
        ImGui::PopFont();
        /// @end Text

        /// @begin Separator
        ImRad::Spacing(1);
        ImRect r1 = ImGui::GetCurrentWindow()->InnerRect;
        ImGui::PushClipRect(r1.Min, r1.Max, false);
        ImGui::SetCursorScreenPos({ r1.Min.x, ImGui::GetCursorScreenPos().y });
        ImVec2 wr1 = ImGui::GetCurrentWindow()->WorkRect.Max;
        ImGui::GetCurrentWindow()->WorkRect.Max.x = r1.Max.x;
        ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
        ImGui::PopClipRect();
        ImGui::GetCurrentWindow()->WorkRect.Max = wr1;
        /// @end Separator

        /// @begin Text
        ImRad::Spacing(2);
        ImGui::TextUnformatted(ImRad::Format("built with ImGui {}", IMGUI_VERSION).c_str());
        /// @end Text

        /// @begin Text
        ImGui::TextUnformatted("Tomas Pecholt");
        /// @end Text

        /// @begin Text
        ImRad::Spacing(2);
        ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled));
        ImGui::TextUnformatted("For more information and updates visit");
        ImGui::PopStyleColor();
        /// @end Text

        /// @begin Table
        if (ImGui::BeginTable("table2", 2, ImGuiTableFlags_None, { -1, 0 }))
        {
            ImGui::TableSetupColumn("A", ImGuiTableColumnFlags_WidthFixed, 0);
            ImGui::TableSetupColumn("B", ImGuiTableColumnFlags_WidthStretch, 0);
            ImGui::TableNextRow(0, 0);
            ImGui::TableSetColumnIndex(0);
            /// @separator

            /// @begin Text
            ImGui::PushStyleColor(ImGuiCol_Text, 0xff003398);
            ImGui::TextUnformatted("Project page");
            ImGui::PopStyleColor();
            if (ImGui::IsItemHovered())
                ImGui::SetMouseCursor(7);
            if (ImGui::IsItemHovered())
                HoverURL();
            if (ImGui::IsItemClicked())
                OpenURL();
            /// @end Text

            /// @begin Text
            ImRad::TableNextColumn(2);
            ImRad::Spacing(1);
            ImGui::PushStyleColor(ImGuiCol_Text, 0xff003398);
            ImGui::TextUnformatted("Tutorials & How To");
            ImGui::PopStyleColor();
            if (ImGui::IsItemHovered())
                ImGui::SetMouseCursor(7);
            if (ImGui::IsItemHovered())
                HoverURL();
            if (ImGui::IsItemClicked())
                OpenURL();
            /// @end Text

            /// @begin Text
            ImRad::TableNextColumn(2);
            ImRad::Spacing(1);
            ImGui::PushStyleColor(ImGuiCol_Text, 0xff003398);
            ImGui::TextUnformatted("Report a bug");
            ImGui::PopStyleColor();
            if (ImGui::IsItemHovered())
                ImGui::SetMouseCursor(7);
            if (ImGui::IsItemHovered())
                HoverURL();
            if (ImGui::IsItemClicked())
                OpenURL();
            /// @end Text


            /// @separator
            ImGui::EndTable();
        }
        /// @end Table

        /// @begin Table
        ImRad::Spacing(2);
        if (ImGui::BeginTable("table3", 2, ImGuiTableFlags_NoPadOuterX | ImGuiTableFlags_NoPadInnerX, { 0, 0 }))
        {
            ImGui::TableSetupColumn("left-stretch", ImGuiTableColumnFlags_WidthStretch, 0);
            ImGui::TableSetupColumn("content", ImGuiTableColumnFlags_WidthFixed, 0);
            ImGui::TableNextRow(0, 0);
            ImGui::TableSetColumnIndex(0);
            /// @separator

            /// @begin Button
            ImRad::TableNextColumn(1);
            if (ImGui::Button("OK", { 100, 30 }) || ImGui::Shortcut(ImGuiKey_Escape))
            {
                ClosePopup(ImRad::Ok);
            }
            /// @end Button


            /// @separator
            ImGui::EndTable();
        }
        /// @end Table

        /// @separator
        ImGui::EndPopup();
    }
    ImGui::PopStyleVar();
    ImGui::PopStyleVar();
    ImGui::PopStyleColor();
    /// @end TopWindow
}


void AboutDlg::OpenURL()
{
    switch (ImGui::TableGetRowIndex())
    {
    case 0:
        ShellExec(GITHUB_URL);
        break;
    case 1:
        ShellExec(GITHUB_URL + "/wiki");
        break;
    case 2:
        ShellExec(GITHUB_URL + "/issues");
        break;
    }
}

void AboutDlg::HoverURL()
{
    ImVec2 p1 = ImGui::GetItemRectMin();
    ImVec2 p2 = ImGui::GetItemRectMax();
    auto* dl = ImGui::GetWindowDrawList();
    dl->AddLine({ p1.x, p2.y }, { p2.x, p2.y }, 0xff003399);
}
