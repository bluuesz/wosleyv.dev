module Styles = {
  open Css;

  let wrapper =
    style([
      maxWidth(px(680)),
      width(`percent(100.)),
      margin2(~v=px(50), ~h=`auto),
      padding2(~v=px(0), ~h=px(30)),
      display(flexBox),
      justifyContent(center),
      media(
        "(max-width: 740px)",
        [flexDirection(column), alignItems(center)],
      ),
    ]);

  let profileImg =
    style([
      width(px(200)),
      height(px(200)),
      borderRadius(`percent(50.)),
    ]);

  let section =
    style([
      marginLeft(px(75)),
      marginTop(px(25)),
      media("(max-width: 640px)", [marginLeft(px(0))]),
    ]);
};

[@react.component]
let make = (~profile: Data.profile) => {
  <Container>
    <div className=Styles.wrapper>
      <img
        className=Styles.profileImg
        src={profile.avatar_url}
        alt="Image-Profile-Github"
      />
      <section className=Styles.section>
        <Resume profile />
        <Skills data={profile.skills} />
      </section>
    </div>
  </Container>;
};