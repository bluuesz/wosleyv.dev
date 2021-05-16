type styles = {
  top: string,
  left: string,
  right: string,
  bottom: string,
  marginRight: string,
  transform: string,
  width: string,
  height: string,
};

type customStyles = {content: styles};

[@module "react-modal"] [@react.component]
external make:
  (
    ~isOpen: bool,
    ~contentLabel: string,
    ~style: customStyles,
    ~children: React.element
  ) =>
  React.element =
  "default";