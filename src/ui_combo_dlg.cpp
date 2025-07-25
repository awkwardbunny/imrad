// Generated with ImRAD 0.1
// github.com/tpecholt/imrad

#include "ui_combo_dlg.h"

ComboDlg comboDlg;


void ComboDlg::Draw()
{
    /// @begin TopWindow
    std::string id = title + "###" + std::to_string((uint64_t)this);
    ImGui::SetNextWindowSize({ 320, 420 }, ImGuiCond_Appearing);
    if (requestOpen) {
        requestOpen = false;
        ImGui::OpenPopup(id.c_str());
    }
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    bool tmpOpen = true;
    if (ImGui::BeginPopupModal(id.c_str(), &tmpOpen, ImGuiWindowFlags_NoCollapse))
    {
        if (requestClose)
            ImGui::CloseCurrentPopup();
        /// @separator

        /// @begin Input
        if (ImGui::IsWindowAppearing())
            ImGui::SetKeyboardFocusHere();
        ImGui::PushFont(font);
        ImGui::InputTextMultiline("##value", &value, { -1, -44 }, ImGuiInputTextFlags_Multiline);
        ImGui::PopFont();
        /// @end Input

        /// @begin Table
        ImGui::Spacing();
        ImGui::Spacing();
        ImGui::PushStyleVar(ImGuiStyleVar_CellPadding, { 1, 1 });
        if (ImGui::BeginTable("table2416128940960", 2, ImGuiTableFlags_None, { 0, 0 }))
        {
            ImGui::TableSetupColumn("A", ImGuiTableColumnFlags_WidthStretch, 0);
            ImGui::TableSetupColumn("B", ImGuiTableColumnFlags_WidthFixed, 0);
            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0);
            /// @separator

            /// @begin Button
            ImGui::TableNextColumn();
            if (ImGui::Button("OK", { 100, 30 }))
            {
                ClosePopup();
                callback(ImRad::Ok);
            }
            /// @end Button

            /// @begin Button
            ImGui::SameLine(0, 1 * ImGui::GetStyle().ItemSpacing.x);
            if (ImGui::Button("Cancel", { 100, 30 }) ||
                ImGui::IsKeyPressed(ImGuiKey_Escape))
            {
                ClosePopup();
            }
            /// @end Button


            /// @separator
            ImGui::EndTable();
        }
        ImGui::PopStyleVar();
        /// @end Table

        /// @separator
        ImGui::EndPopup();
    }
    /// @end TopWindow
}

void ComboDlg::OpenPopup(std::function<void(ImRad::ModalResult)> clb)
{
    callback = clb;
    requestOpen = true;
    requestClose = false;

// Add your init code here
}

void ComboDlg::ClosePopup()
{
    requestClose = true;
}
