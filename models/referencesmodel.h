#pragma once

#include "../hooks/idisassemblercommand.h"
#include "disassemblermodel.h"
#include <rdapi/rdapi.h>

class ReferencesModel : public DisassemblerModel
{
    Q_OBJECT

    public:
        explicit ReferencesModel(const IDisassemblerCommand* command, QObject *parent = nullptr);
        ~ReferencesModel();
        void setDisassembler(RDDisassembler* disassembler) override;
        void xref(rd_address address);

    public:
        QModelIndex index(int row, int column, const QModelIndex&) const override;
        QVariant data(const QModelIndex &index, int role) const override;
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
        int rowCount(const QModelIndex&) const override;
        int columnCount(const QModelIndex&) const override;

    public slots:
        void clear();

    private:
        QString direction(RDDocument* doc, rd_address address) const;

    private:
        RDRenderer* m_renderer{nullptr};
        const IDisassemblerCommand* m_command;
        const rd_address* m_references{nullptr};
        size_t m_referencescount{0};
};
