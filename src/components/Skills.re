module Styles = {
  open Css;

  let container = style([marginTop(px(30)), marginBottom(px(25))]);

  let tagsSection = style([display(flexBox), flexWrap(`wrap)]);

  let skills =
    style([
      marginTop(px(20)),
      display(grid),
      gridTemplateColumns([fr(1.0), fr(1.0), fr(1.0)]),
      gridGap(px(20)),
      media(
        "(max-width: 640px)",
        [gridTemplateColumns([fr(1.0), fr(1.0)]), gridGap(px(10))],
      ),
    ]);
};

[@react.component]
let make = (~data: list(Data.skill)) => {
  <div className=Styles.container>
    <Title> "Skills / Interests" </Title>
    <section className=Styles.tagsSection>
      <SkillTag tag=Data.WorkExperience />
      <SkillTag tag=Data.Learning />
      <SkillTag tag=Data.Interested />
    </section>
    <section className=Styles.skills>
      {data
       |> List.mapi((i, skill: Data.skill) =>
            <SkillItem key={i |> string_of_int} skill />
          )
       |> Array.of_list
       |> ReasonReact.array}
    </section>
  </div>;
};