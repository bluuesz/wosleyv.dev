type tag =
  | WorkExperience
  | Learning
  | Interested;

type skill = {
  name: string,
  tags: list(tag),
};

type about = {paragraph: string};

type resume = list(about);

type profile = {
  name: string,
  avatar_url: string,
  resume,
  role: string,
  skills: list(skill),
};

let string_of_tag =
  fun
  | WorkExperience => "work experience"
  | Learning => "learning"
  | Interested => "interested";

let color_of_tag =
  fun
  | WorkExperience => Css.rgb(224, 109, 109)
  | Learning => Css.rgb(40, 175, 250)
  | Interested => Css.rgb(0, 107, 117);

let linear_percent = list_color => {
  let size = List.length(list_color);

  switch (size) {
  | 3 => [|13.19, 52.85, 82.63|]
  | 2 => [|30., 100.|]
  | _ => [|100., 0.|]
  };
};

let array_color_of_tag = skills => {
  let colors = skills.tags |> List.map(item => item |> color_of_tag);

  let linear_to_gradient =
    colors
    |> List.mapi((i, color) =>
         (`percent((colors |> linear_percent)[i]), color)
       );

  let linear_or_solid =
    List.length(colors) === 1
      ? List.hd(colors) : Css.linearGradient(`deg(90.), linear_to_gradient);

  linear_or_solid;
};

let me = {
  name: "Wosley Vacemberg",
  avatar_url: "https://avatars.githubusercontent.com/u/51493181?v=4",
  resume: [
    {
      paragraph: "Software developer, passionate about functional programming and computer science",
    },
    {
      paragraph: "I am also an enthusiast of theoretical physics. In my free time I usually study about toolings, category theory and a few more things as much as random",
    },
  ],
  role: "Software Developer",
  skills: [
    {name: "JavaScript", tags: [WorkExperience]},
    {name: "TypeScript", tags: [WorkExperience]},
    {name: "GraphQL", tags: [WorkExperience, Learning, Interested]},
    {name: "SQL/NoSQL", tags: [WorkExperience]},
    {name: "gRPC", tags: [Interested, Learning]},
    {name: "ReasonML/OCaml", tags: [Interested, Learning]},
    {name: "Rust", tags: [Interested]},
    {name: "Elixir", tags: [Interested, Learning]},
    {name: "Haskell", tags: [Interested]},
  ],
};